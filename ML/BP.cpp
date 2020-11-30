#include <bits/stdc++.h>
using namespace std;

#define in 784
#define out 10
using namespace std ;
double data_out[50];//输出层输出
double w[50][1000],b[50];//输出层权重
double delta[50];//误差项
vector<double>labels;
vector<vector<double> >images;//训练集
vector<double>labels1;
vector<vector<double> >images1;//测试集
void test();
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
 
		cout << "magic number = " << magic_number << endl;
 
		cout << "number of images = " << number_of_images << endl;
 
 
 
 
 
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
 
 
 
		cout << "magic number = " << magic_number << endl;
 
		cout << "number of images = " << number_of_images << endl;
 
		cout << "rows = " << n_rows << endl;
 
		cout << "cols = " << n_cols << endl;
 
 
 
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
void softmax(double data_out[])
{
    double sum=0.0;
    for(int i=0;i<out;i++) sum+=exp(data_out[i]);
    for(int i=0;i<out;i++) data_out[i]=exp(data_out[i])/sum;
}
void Network()
{
    memset(data_out,0,sizeof(data_out));
    freopen("out.txt","r",stdin);
    for(int i=0;i<out;i++)
    {
        for(int j=0;j<in;j++)
        {
            scanf("%lf",&w[i][j]);
        }
    }
    scanf("%lf",&b);
    /*for(int i=0;i<out;i++)
    for(int j=0;j<in;j++)
    w[i][j]=-0.5;*/
}
void cp(int t)
{
    memset(data_out,0,sizeof(data_out));
    double maxx=-100000000;
    for(int i=0;i<out;i++)
    {
        for(int j=0;j<in;j++)
        {
            data_out[i]+=w[i][j]*images[t][j];
        }
        data_out[i]+=b[i];
        maxx=max(maxx,data_out[i]);
    }
    //printf("%.5f\n",maxx);
    for(int i=0;i<out;i++)
    {
        data_out[i]-=maxx;
    }
    softmax(data_out);
    /*for(int i=0;i<out;i++)
    printf("%.5f ",data_out[i]);
    printf("\n");*/
}
int test_out(int t)
{
    memset(data_out,0,sizeof(data_out));
    double maxx=-100000000;
    for(int i=0;i<out;i++)
    {
        for(int j=0;j<in;j++)
        {
            data_out[i]+=w[i][j]*images1[t][j];
        }
        data_out[i]+=b[i];
        maxx=max(maxx,data_out[i]);
    }
    for(int i=0;i<out;i++)
    {
        data_out[i]-=maxx;
    }
    softmax(data_out);
    int ans=-1,sign=-1;
    for(int i=0;i<out;i++)
    {
        if(data_out[i]>sign)
        {
            sign=data_out[i];
            ans=i;
        }
    }
    return ans;
}
void bp(int t)
{
    for(int i=0;i<out;i++)
    {
        if(i==(int)labels[t]) delta[i]=data_out[i]-1.0;
        else delta[i]=data_out[i];
        //printf("%.5f ",delta[i]);
    }
    //printf("\n");
    for(int i=0;i<in;i++)
    {
        for(int j=0;j<out;j++)
        w[j][i]-=0.3*delta[j]*images[t][i];
    }
    for(int j=0;j<out;j++) b[j]-=0.3*delta[j];
}
void train()
{
    for(int k=1;k<=100;k++)
    {
        double err=0;
        for(int i=0;i<60000;i++)
        {
            cp(i);
            err-=log(data_out[(int)labels[i]]);
            bp(i);
        }
        printf("step: %d   loss: %.5f\n",k,err/10000.0);//每次记录一遍数据集的平均误差
        if(k%5==0) test();
    }
 
}
void test()
{
	int sum=0;
	for(int i=0;i<10000;i++)
	{
	    int ans=test_out(i);
	    int label=int(labels1[i]);
	    if(ans==label) sum++;
	    //printf("%d %d\n",ans,label);
	}
	//printf("\n");
	//for(int i=0;i<out;i++) printf("%.5f ",data_out[i]);
	//printf("\n");
	printf("precision: %.6f\n",1.0*sum/10000);
}
int main()
{
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
	}
	//归一化处理图像
    Network();//网络初始化
    test();
    train();
    freopen("out.txt","w",stdout);
    for(int i=0;i<out;i++)
    {
        for(int j=0;j<in;j++)
        {
            printf("%.5f ",w[i][j]);
        }
    }
    //保存参数
    printf("%.5f",b);
    return 0;
}