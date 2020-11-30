#include <bits/stdc++.h>
using namespace std ;
vector<double>labels;
vector<vector<double> >images;//训练集
vector<double>labels1;
vector<vector<double> >images1;//测试集
const int train_number=20000;//训练样本数
const int test_number=5000;//测试样本数
const int out=10;
const double alpha=0.01;//学习率
int step;
struct layer//定义卷积网络中的层
{
    int L,W,H;
    double m[30][30][5];
    double b[30][30][5];
    double delta[30][30][5];
    void init()
    {
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
                for(int k=0;k<5;k++)
                    m[i][j][k]=0.01*(rand()%100);
    }
};
struct fcnn_layer//定义全连接网络中的层
{
    int length;
    double m[1000];
    double b[1000];
    double delta[1000];
    double w[20][1000];
    void init()
    {
        for(int i=0;i<20;i++)
            for(int j=0;j<1000;j++)
                w[i][j]=0.01*(rand()%100);
    }
};
struct Network//定义CNN
{
    layer Input_layer;
    layer conv_layer1;
    layer pool_layer1;
    layer filter1[5];
    fcnn_layer fcnn_input;
    fcnn_layer fcnn_w;
    fcnn_layer fcnn_outpot;
}CNN;
 
void init()//权重初始化
{
    CNN.Input_layer.init();
    CNN.conv_layer1.init();
    CNN.pool_layer1.init();
    for(int i=0;i<5;i++) CNN.filter1[i].init();
    CNN.fcnn_input.init();
    CNN.fcnn_w.init();
    CNN.fcnn_outpot.init();
}
 
 
layer conv(layer A,layer B[],int number,layer C,int flag);//卷积函数，表示卷积层A与number个filterB相卷积
layer CNN_Input(int num,layer A);//将图像输入卷积层
fcnn_layer Classify_input(layer A,fcnn_layer B);//将卷积提取特征输入到全连接神经网络
layer pool_input(layer A,fcnn_layer B);//全连接层的误差项传递到CNN中
layer pool_delta(layer A,layer B);//当前层为池化层的敏感项传递
fcnn_layer softmax(fcnn_layer A);//softmax函数
double Relu(double x);//Relu函数
layer Update(layer A,layer B,layer C);//filter更新
layer maxpooling(layer conv_layer,layer A);//池化前向输出
fcnn_layer fcnn_Mul(fcnn_layer A,fcnn_layer B,fcnn_layer C);//全连接层前向输出
double sum(layer A);//矩阵求和，此处用于敏感项求和
double sum1(layer A,layer B,int x,int y);
double sigmod(double x);
void test();
int test_out(int t);
 
/**************************此段为读取MNIST数据集模块**************/
int ReverseInt(int i)
{
	unsigned char ch1, ch2, ch3, ch4;
	ch1 = i & 255;
	ch2 = (i >> 8) & 255;
	ch3 = (i >> 16) & 255;
	ch4 = (i >> 24) & 255;
	return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}
void read_Mnist_Label(string filename, vector<double>&labels)
{
    ifstream file;
	file.open("train-labels.idx1-ubyte", ios::binary);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		file.read((char*)&number_of_images, sizeof(number_of_images));
		magic_number = ReverseInt(magic_number);
		number_of_images = ReverseInt(number_of_images);
		for (int i = 0; i < number_of_images; i++)
		{
			unsigned char label = 0;
			file.read((char*)&label, sizeof(label));
			labels.push_back((double)label);
		}
	}
}
void read_Mnist_Images(string filename, vector<vector<double> >&images)
{
	ifstream file("train-images.idx3-ubyte", ios::binary);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;
		unsigned char label;
		file.read((char*)&magic_number, sizeof(magic_number));
		file.read((char*)&number_of_images, sizeof(number_of_images));
		file.read((char*)&n_rows, sizeof(n_rows));
		file.read((char*)&n_cols, sizeof(n_cols));
		magic_number = ReverseInt(magic_number);
		number_of_images = ReverseInt(number_of_images);
		n_rows = ReverseInt(n_rows);
		n_cols = ReverseInt(n_cols);
		for (int i = 0; i < number_of_images; i++)
		{
			vector<double>tp;
			for (int r = 0; r < n_rows; r++)
			{
				for (int c = 0; c < n_cols; c++)
				{
					unsigned char image = 0;
					file.read((char*)&image, sizeof(image));
                    tp.push_back(image);
				}
			}
			images.push_back(tp);
		}
	}
}
void read_Mnist_Label1(string filename, vector<double>&labels)
{
    ifstream file;
	file.open("t10k-labels.idx1-ubyte", ios::binary);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		file.read((char*)&number_of_images, sizeof(number_of_images));
		magic_number = ReverseInt(magic_number);
		number_of_images = ReverseInt(number_of_images);
		for (int i = 0; i < number_of_images; i++)
		{
			unsigned char label = 0;
			file.read((char*)&label, sizeof(label));
			labels.push_back((double)label);
		}
	}
}
void read_Mnist_Images1(string filename, vector<vector<double> >&images)
{
	ifstream file("t10k-images.idx3-ubyte", ios::binary);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;
		unsigned char label;
		file.read((char*)&magic_number, sizeof(magic_number));
		file.read((char*)&number_of_images, sizeof(number_of_images));
		file.read((char*)&n_rows, sizeof(n_rows));
		file.read((char*)&n_cols, sizeof(n_cols));
		magic_number = ReverseInt(magic_number);
		number_of_images = ReverseInt(number_of_images);
		n_rows = ReverseInt(n_rows);
		n_cols = ReverseInt(n_cols);
		for (int i = 0; i < number_of_images; i++)
		{
			vector<double>tp;
			for (int r = 0; r < n_rows; r++)
			{
				for (int c = 0; c < n_cols; c++)
				{
					unsigned char image = 0;
					file.read((char*)&image, sizeof(image));
					tp.push_back(image);
				}
			}
			images.push_back(tp);
		}
	}
}
/**************************************************************/
 
layer conv(layer A,layer B[],int number,layer C)
{
    memset(C.m,0,sizeof(C.m));
    for(int i=0;i<number;i++)
    {
        B[i].L=B[i].W=5;
        B[i].H=1;
    }
    C.L=A.L-B[0].L+1;
    C.W=A.W-B[0].W+1;
    C.H=number;
    for(int num=0;num<number;num++)
        for(int i=0;i<C.L;i++)
            for(int j=0;j<C.W;j++)
            {
                for(int a=0;a<B[0].L;a++)
                    for(int b=0;b<B[0].W;b++)
                        for(int k=0;k<A.H;k++)
                            C.m[i][j][num]+=A.m[i+a][j+b][k]*B[num].m[a][b][k];
                C.m[i][j][num]=Relu(C.m[i][j][num]+C.b[i][j][num]);
            }
    return C;
}
layer CNN_Input(int num,layer A,int flag)
{
    A.L=A.W=28;
    A.H=1;
    int x=0;
    for(int i=0;i<28;i++)
    {
        for(int j=0;j<28;j++)
        {
            for(int k=0;k<1;k++)
            {
                if(flag==0) A.m[i][j][k]=images[num][x];
                else if(flag==1) A.m[i][j][k]=images1[num][x];
                x++;
            }
        }
    }
    return A;
}
fcnn_layer Classify_input(layer A,fcnn_layer B)
{
    int x=0;
    B.m[x++]=1.0;
    for(int i=0;i<A.L;i++)
        for(int j=0;j<A.W;j++)
            for(int k=0;k<A.H;k++)
                B.m[x++]=sigmod(A.m[i][j][k]);
    B.length=x;
    return B;
}
layer pool_input(layer A,fcnn_layer B)
{
    int x=1;
    for(int i=0;i<A.L;i++)
        for(int j=0;j<A.W;j++)
            for(int k=0;k<A.H;k++)
                A.delta[i][j][k]=B.delta[x++];
    return A;
}
layer pool_delta(layer A,layer B)
{
    for(int k=0;k<A.H;k++)
        for(int i=0;i<A.L;i+=2)
            for(int j=0;j<A.W;j+=2)
            {
                if(fabs(A.m[i][j][k]-B.m[i/2][j/2][k])<0.01) A.delta[i][j][k]=B.delta[i/2][j/2][k];
                else A.delta[i][j][k]=0;
            }
    return A;
}
layer maxpooling(layer conv_layer,layer A)
{
    A.L=conv_layer.L/2;
    A.W=conv_layer.W/2;
    A.H=conv_layer.H;
    for(int k=0;k<conv_layer.H;k++)
        for(int i=0;i<conv_layer.L;i+=2)
            for(int j=0;j<conv_layer.W;j+=2)
                A.m[i/2][j/2][k]=max(max(conv_layer.m[i][j][k],conv_layer.m[i+1][j][k]),
                                 max(conv_layer.m[i][j+1][k],conv_layer.m[i+1][j+1][k]));
    return A;
}
fcnn_layer fcnn_Mul(fcnn_layer A,fcnn_layer B,fcnn_layer C)
{
    memset(C.m,0,sizeof(C.m));
    C.length=out;
    for(int i=0;i<C.length;i++)
    {
        for(int j=0;j<A.length;j++)
        {
            C.m[i]+=B.w[i][j]*A.m[j];
        }
        C.m[i]+=B.b[i];
    }
    return C;
}
double sigmod(double x)
{
    return 1.0/(1.0+exp(-x));
}
double sum(layer A)
{
    double a=0;
    for(int i=0;i<A.L;i++)
        for(int j=0;j<A.W;j++)
            for(int k=0;k<A.H;k++)
                a+=A.delta[i][j][k];
    return a;
}
double sum1(layer A,layer B,int x,int y)
{
    double a=0;
    for(int i=0;i<A.L;i++)
        for(int j=0;j<A.W;j++)
            for(int k=0;k<A.H;k++)
                a+=A.delta[i][j][k]*B.m[i+x][j+y][k];
    return a;
}
layer Update(layer A,layer B,layer C)
{
    for(int i=0;i<A.L;i++)
        for(int j=0;j<A.W;j++)
            for(int k=0;k<A.H;k++)
            {
                A.m[i][j][k]-=alpha*sum1(A,B,i,j);
                C.b[i][j][k]-=alpha*sum(A);
            }
    return A;
}
double Relu(double x)
{
    return max(0.0,x);
}
fcnn_layer softmax(fcnn_layer A)
{
    double sum=0.0;double maxx=-100000000;
    for(int i=0;i<out;i++) maxx=max(maxx,A.m[i]);
    for(int i=0;i<out;i++) sum+=exp(A.m[i]-maxx);
    for(int i=0;i<out;i++) A.m[i]=exp(A.m[i]-maxx)/sum;
    return A;
}
void forward_propagation(int num,int flag)//做一次前向输出
{
    CNN.Input_layer=CNN_Input(num,CNN.Input_layer,flag);
    CNN.conv_layer1=conv(CNN.Input_layer,CNN.filter1,5,CNN.conv_layer1);
    CNN.pool_layer1=maxpooling(CNN.conv_layer1,CNN.pool_layer1);
    //CNN.conv_layer2=conv(CNN.pool_layer1,CNN.filter2,3,CNN.conv_layer2,0);
    //CNN.pool_layer2=maxpooling(CNN.conv_layer2,CNN.pool_layer2);
    CNN.fcnn_input=Classify_input(CNN.pool_layer1,CNN.fcnn_input);
    //for(int i=0;i<CNN.fcnn_input.length;i++) printf("%.5f ",CNN.fcnn_input.m[i]);
    CNN.fcnn_outpot=fcnn_Mul(CNN.fcnn_input,CNN.fcnn_w,CNN.fcnn_outpot);
    CNN.fcnn_outpot=softmax(CNN.fcnn_outpot);
    for(int i=0;i<out;i++)
    {
        if(i==(int)labels[num]) CNN.fcnn_outpot.delta[i]=CNN.fcnn_outpot.m[i]-1.0;
        else CNN.fcnn_outpot.delta[i]=CNN.fcnn_outpot.m[i];
        //printf("%.5f ",CNN.fcnn_outpot.m[i]);
    }
    //printf(" %.0f\n",labels[num]);
}
void back_propagation()//反向传播算法
{
    memset(CNN.fcnn_input.delta,0,sizeof(CNN.fcnn_input.delta));
    for(int i=0;i<CNN.fcnn_input.length;i++)
    {
        for(int j=0;j<out;j++)
        {
            CNN.fcnn_input.delta[i]+=CNN.fcnn_input.m[i]*(1.0-CNN.fcnn_input.m[i])*CNN.fcnn_w.w[j][i]*CNN.fcnn_outpot.delta[j];
        }
    }
    for(int i=0;i<CNN.fcnn_input.length;i++)
    {
        for(int j=0;j<out;j++)
        {
            CNN.fcnn_w.w[j][i]-=alpha*CNN.fcnn_outpot.delta[j]*CNN.fcnn_input.m[i];
            CNN.fcnn_w.b[j]-=alpha*CNN.fcnn_outpot.delta[j];
            //printf("%.5f ",CNN.fcnn_w.w[j][i]);
        }
    }
    CNN.pool_layer1=pool_input(CNN.pool_layer1,CNN.fcnn_input);
    CNN.conv_layer1=pool_delta(CNN.conv_layer1,CNN.pool_layer1);//pooling误差传递
    //CNN.pool_layer1=conv(CNN.conv_layer1,CNN.filter2,3,CNN.pool_layer1,1);//conv误差传递
    for(int i=0;i<5;i++) CNN.filter1[i]=Update(CNN.filter1[i],CNN.Input_layer,CNN.conv_layer1);
}
void train()
{
    step=0;
    for(int time=0;time<100;time++)
    {
        double err=0;
        for(int i=0;i<train_number;i++)
        {
            forward_propagation(i,0);
            err-=log(CNN.fcnn_outpot.m[(int)labels[i]]);
            back_propagation();
        }
        printf("step: %d   loss:%.5f\n",time,1.0*err/train_number);//每次记录一遍数据集的平均误差
        test();
    }
}
void test()
{
	int sum=0;
	for(int i=0;i<test_number;i++)
	{
	    int ans=test_out(i);
	    int label=int(labels1[i]);
	    if(ans==label) sum++;
	    //printf("%d %d\n",ans,label);
	}
	//printf("\n");
	//for(int i=0;i<out;i++) printf("%.5f ",data_out[i]);
	//printf("\n");
	printf("step:%d   precision: %.5f\n",++step,1.0*sum/test_number);
}
int test_out(int t)
{
    forward_propagation(t,1);
    int ans=-1;
    double sign=-1;
    for(int i=0;i<out;i++)
    {
        if(CNN.fcnn_outpot.m[i]>sign)
        {
            sign=CNN.fcnn_outpot.m[i];
            ans=i;
        }
    }
    return ans;
}
int main()
{
    init();
    read_Mnist_Label("t10k-labels.idx1-ubyte", labels);
	read_Mnist_Images("t10k-images.idx3-ubyte", images);
	read_Mnist_Label1("t10k-labels.idx1-ubyte", labels1);
	read_Mnist_Images1("t10k-images.idx3-ubyte", images1);//读取mnist数据集
	for (int i = 0; i < images1.size(); i++)
	{
		for (int j = 0; j < images1[0].size(); j++)
		{
            images1[i][j]/=255.0;
		}
	}
	for (int i = 0; i < images.size(); i++)
	{
		for (int j = 0; j < images[0].size(); j++)
		{
            images[i][j]/=255.0;
		}
	}//图像归一化
	train();
    test();
    return 0;
}