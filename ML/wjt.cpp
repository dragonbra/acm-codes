#include <bits/stdc++.h>
using namespace std ;
vector<double>labels;
vector<vector<double> >images;//训练集
vector<double>labels1;
vector<vector<double> >images1;//测试集
const int train_number=10000;
const int test_number=500;
int a[20];
int KNN(int i,int k);
struct node
{
    int labels;
    int dis;
}q[train_number+100];
bool cmp(node a,node b)
{
    return a.dis<b.dis;
}
/**********************************/
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
/**************以上为MNIST数据集读取部分，下面开始KNN算法**************/
void test(int k)
{
    int sum=0;
    for(int i=0;i<test_number;i++)
    {
        int predict=KNN(i,k);
        //printf("pre:%d label:%d\n",predict,(int)labels1[i]);
        if(predict==(int)labels1[i]) sum++;
    }
    printf("k=%d    precision: %.5f\n",k,1.0*sum/test_number);
}

int KNN(int number,int k)//预测函数
{
    memset(q,0,sizeof(q));
    memset(a,0,sizeof(a));
    int dis=0;
    for(int i=0;i<train_number;i++)
    {
        for(int j=0;j<784;j++)
            dis+=(images[i][j]-images1[number][j])*(images[i][j]-images1[number][j]);
        dis=sqrt(dis);//获得欧式距离
        q[i].dis=(int)dis;
        q[i].labels=(int)labels[i];
    }
    sort(q,q+train_number,cmp);
    for(int i=0;i<k;i++)
    {
        a[q[i].labels]++;
    }
    int ans=-1,minn=-1;
    for(int i=0;i<10;i++)
    {
        if(a[i]>minn)
        {
            minn=a[i];
            ans=i;
        }
    }
    return ans;
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
            images1[i][j]=(images1[i][j]>0)?1:0;
		}
	}
	for (int i = 0; i < images.size(); i++)
	{
		for (int j = 0; j < images[0].size(); j++)
		{
            images[i][j]=(images[i][j]>0)?1:0;
		}
	}
	test(1);
	test(2);
	test(3);
	test(4);
	freopen("1.txt","w",stdout);
	int len1=images1.size();
	for(int i=0;i<len1;i++){
		int len=images1[i].size();
		int cnt=0;
		for(int j=0;j<len;j++){
			cout<<images1[i][j]<<' ';
			cnt++;
			if(cnt==int(sqrt(len))){
				cnt=0;
				cout<<endl;
			} 
		}
		cout<<endl;
	}
	return 0;
}
