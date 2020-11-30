/*
    @作者:CHH
    @版本V1.0
    @邮箱:chh_is_dog@163.com
    @编写时间:2019-7-29
    @功能:使用反向传播神经网络识别手写字体
    @使用方法:
        1.生成的文件会自动到同一目录下寻找MNIST的四个手写字体库
        2.字体库下载地址:http://yann.lecun.com/exdb/mnist/
        3.DEBUG模式下只会使用少量训练样本
        4.输出流为stdout
    @模型结构:
        1.激活函数:sigmod
        2.损失函数:交叉熵损失函数
        3.迭代方式:反向传播+最速梯度下降
        4.学习率=0.5
        5.三层神经元,连接方式: 全连接
            a.输入层:28*28个
            b.隐藏层:20个
            c.输出层:10个
    @程序结构:分为4个模块,面向过程化
        1.实现矩阵类以及矩阵的基本操作
        2.读入MNIST的数据并进行清洗
        3.实现FP->BP->GD
        4.模型评估
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define DEBUG

const int IMAGE_SIZE = 28 * 28;
const int LABEL_SIZE = 1;
const int OUT_SIZE = 10;
const double INF = 1.7e308;
const double EPS = 1e-6;
const double E = 2.718281828459;
#ifdef DEBUG
const int NUM_TRAIN = 100;
const int NUM_TEST = 10;
#else
const int NUM_TRAIN = 60000;
const int NUM_TEST = 10000;
#endif

//矩阵
typedef vector<vector<double>> Matrix;
//矩阵构造
void construct(Matrix &mat, int row, int col)
{
    mat.resize(row);
    for (int i = 0; i < row; i++)
        mat[i].resize(col);
}
void construct(Matrix &mat, int row, int col, double val)
{
    mat.resize(row);
    for (int i = 0; i < row; i++)
        mat[i].resize(col, val);
}
//矩阵加法
inline const Matrix addition(const Matrix &a, const Matrix &b)
{
    if (a.size() != b.size() || a[0].size() != b[0].size())
        throw "ERROR: Matrix addition format wrong";
    Matrix res;
    res.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i].resize(a[0].size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            res[i][j] = a[i][j] + b[i][j];
    return res;
}
//矩阵减法
inline const Matrix subtract(const Matrix &a, const Matrix &b)
{
    if (a.size() != b.size() || a[0].size() != b[0].size())
        throw "ERROR: Matrix subtract format wrong";
    Matrix res;
    res.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i].resize(a[0].size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            res[i][j] = a[i][j] - b[i][j];
    return res;
}
//矩阵乘法
inline const Matrix multiply(const Matrix &a, const Matrix &b)
{
    if (a[0].size() != b.size())
        throw "ERROR: Matrix multiply format wrong";
    Matrix res;
    res.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i].resize(b[0].size(), 0);
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            for (int k = 0; k < a[0].size(); k++)
                res[i][j] += a[i][k] * b[k][j];
    return res;
}
//矩阵点乘
inline const Matrix matmul(const Matrix &a, const Matrix &b)
{
    if (a.size() != b.size() || a[0].size() != b[0].size())
        throw "ERROR: Matrix matmul format wrong";
    Matrix res;
    res.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i].resize(a[0].size());
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            res[i][j] = a[i][j] * b[i][j];
    return res;
}
//矩阵对标量的乘法
inline const Matrix multiply(const Matrix &a, double val)
{
    Matrix res;
    res.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i].resize(a[0].size());
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            res[i][j] = a[i][j] * val;
    return res;
}
//矩阵对标量的除法
inline const Matrix division(const Matrix &a, double val)
{
    Matrix res;
    res.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i].resize(a[0].size());
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            res[i][j] = a[i][j] / val;
    return res;
}

//矩阵转置
inline const Matrix transpose(const Matrix &mat)
{
    Matrix res;
    res.resize(mat[0].size());
    for (int i = 0; i < res.size(); i++)
        res[i].resize(mat.size());
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            res[i][j] = mat[j][i];
    return res;
}
//打印矩阵
void printMatrix(const Matrix &mat)
{
    cout << mat.size() << " * " << mat[0].size() << endl;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

//打印图片
inline void printImage(const Matrix &data)
{
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            printf("%.2lf ", data[28 * i + j][0]);
        }
        cout << '\n';
    }
}

//数据点
struct Point
{
    //double image[IMAGE_SIZE];
    //bool label[OUT_SIZE];
    Matrix image;
    Matrix label;
    Point(char *image, uint8_t num)
    {
        this->image.resize(IMAGE_SIZE);
        for (int i = 0; i < IMAGE_SIZE; i++)
        {
            this->image[i].resize(1);
            this->image[i][0] = (uint8_t)image[i];
        }
        label.resize(OUT_SIZE);
        for (int i = 0; i < OUT_SIZE; i++)
        {
            label[i].resize(1);
            label[i][0] = 0;
        }
        label[num][0] = 1;
    }
};
vector<Point> TrainData, TestData;

//读入数据
void readALLData(vector<Point> &train, vector<Point> &test)
{
    char rubbish[16];
    ifstream train_images("./train-images.idx3-ubyte", ios::binary | ios::in);
    ifstream train_labels("./train-labels.idx1-ubyte", ios::binary | ios::in);
    train_images.read(rubbish, 16); //4*32bit_integer
    train_labels.read(rubbish, 8);  //2*32bit_integer
    for (int i = 0; i < NUM_TRAIN; i++)
    {
        char image[IMAGE_SIZE];
        uint8_t num;
        train_images.read(image, IMAGE_SIZE);
        train_labels.read((char *)(&num), LABEL_SIZE);
        train.push_back({image, num});
        // printImage(train[i].image);
    }

    ifstream test_images("./t10k-images.idx3-ubyte", ios::binary | ios::in);
    ifstream test_labels("./t10k-labels.idx1-ubyte", ios::binary | ios::in);
    test_images.read(rubbish, 16); //4*32bit_integer
    test_labels.read(rubbish, 8);  //2*32bit_integer
    for (int i = 0; i < NUM_TEST; i++)
    {
        char image[IMAGE_SIZE];
        uint8_t num;
        test_images.read(image, IMAGE_SIZE);
        test_labels.read((char *)(&num), LABEL_SIZE);
        test.push_back({image, num});
    }
    // printImage(test[0].image);
    // for(int i=0; i<10; i++)
    //     if(test[0].label[i])
    //         cout<<i;
}

//归一化
void Normalize(vector<Point> &set)
{
    vector<Point>::iterator it;
    it = set.begin();
    while (it != set.end())
    {
        for (int i = 0; i < IMAGE_SIZE; i++)
        {
            it->image[i][0] /= 180.0; //映射到[0, 1.4]之间
        }

        it++;
    }
}

//神经网络

//网络结构
//三层：输入:28*28->隐藏:20->输出:10
const int LAYER_NUM = 3;
const int NEURE_NUM[LAYER_NUM] = {IMAGE_SIZE, 20, OUT_SIZE};

//激活函数
inline double sigmod(double x)
{
    return 1.0 / (1 + pow(E, -x)); //BUG,分母还有个1+
}
inline const Matrix sigmod(const Matrix &mat)
{
    Matrix res;
    construct(res, mat.size(), mat[0].size());
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            res[i][j] = sigmod(mat[i][j]);
    return res;
}

//相关变量
vector<Matrix> Weight;     //权重
vector<Matrix> Bias;       //偏移量
vector<Matrix> Error;      //误差
vector<Matrix> der_Weight; //权重的偏导数
vector<Matrix> der_Bias;   //偏移量的偏导数
vector<Matrix> receive;    //接受的值
vector<Matrix> activation; //激发后的值
int iteration;             //迭代次数
double step;               //学习率
//神经网络参数初始化
void initialize(void)
{
    //超参数
    iteration = 200;
    step = 0.5;
    //权重初始化
    Weight.resize(LAYER_NUM);
    for (int i = 1; i < LAYER_NUM; i++)
    {
        //构造形状
        construct(Weight[i], NEURE_NUM[i], NEURE_NUM[i - 1]);
        //随机化参数
        srand(time(0));
        for (int j = 0; j < Weight[i].size(); j++)
            for (int k = 0; k < Weight[i][0].size(); k++)
            {
                Weight[i][j][k] = ((double)(rand() % 1000) / 700 - 0.5) * sqrt(1.0 / NEURE_NUM[i - 1]);
                //cout << Weight[i][j][k] << endl;
            }
    }
    //偏移量初始化
    Bias.resize(LAYER_NUM);
    for (int i = 1; i < LAYER_NUM; i++)
    {
        //构造形状
        //0初始化
        construct(Bias[i], NEURE_NUM[i], 1, 0);
    }
    //误差初始化
    Error.resize(LAYER_NUM);
    for (int i = 1; i < LAYER_NUM; i++)
    {
        //构造形状
        //0初始化
        construct(Error[i], NEURE_NUM[i], 1, 0);
    }
    //权重的偏导数初始化
    der_Weight.resize(LAYER_NUM);
    for (int i = 1; i < LAYER_NUM; i++)
    {
        //构造形状
        //0初始化
        construct(der_Weight[i], NEURE_NUM[i], NEURE_NUM[i - 1], 0);
    }
    //偏移量的偏导数初始化
    der_Bias.resize(LAYER_NUM);
    for (int i = 1; i < LAYER_NUM; i++)
    {
        //构造形状
        //0初始化
        construct(der_Bias[i], NEURE_NUM[i], 1, 0);
    }
    //接受的值初始化
    receive.resize(LAYER_NUM);
    for (int i = 1; i < LAYER_NUM; i++)
    {
        //构造形状
        //0初始化
        construct(receive[i], NEURE_NUM[i], 1, 0);
    }
    //激发后的值初始化
    activation.resize(LAYER_NUM);
    for (int i = 0; i < LAYER_NUM; i++)
    {
        //构造形状
        //0初始化
        construct(activation[i], NEURE_NUM[i], 1, 0);
    }
}

//清零
inline void zeroClear(vector<Matrix> &mat)
{
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[i].size(); j++)
            for (int k = 0; k < mat[i][0].size(); k++)
                mat[i][j][k] = 0;
}

//单个样本点前向传播
inline void forwardPropagation(const Point &point)
{
    activation[0] = point.image;
    for (int i = 1; i < LAYER_NUM; i++)
    {
        receive[i] = multiply(Weight[i], activation[i - 1]);
        activation[i] = sigmod(receive[i]);
    }
}

//单个样本点反向传播
inline void backPropagation(const Point &point)
{
    Error[LAYER_NUM - 1] = subtract(activation[LAYER_NUM - 1], point.label);
    Matrix ONE;
    for (int i = LAYER_NUM - 2; i >= 1; i--) //注意是反向传播
    {
        construct(ONE, activation[i].size(), activation[i][0].size(), 1);
        Error[i] = matmul(multiply(transpose(Weight[i + 1]), Error[i + 1]), matmul(activation[i], subtract(ONE, activation[i])));
    }
}
//偏导数累加
inline void accumulateDerivate(void)
{
    for (int i = 1; i < LAYER_NUM; i++)
    {
        der_Weight[i] = addition(der_Weight[i], multiply(Error[i], transpose(activation[i - 1])));
        der_Bias[i] = addition(der_Bias[i], Error[i]);
    }
}
//计算偏导数
inline void calculateDerivate(void)
{
    for (int i = 1; i < LAYER_NUM; i++)
    {
        der_Weight[i] = division(der_Weight[i], NUM_TRAIN);
        der_Bias[i] = division(der_Bias[i], NUM_TRAIN);
    }
}
//梯度下降
inline void gradientDescent(void)
{
    for (int i = 1; i < LAYER_NUM; i++)
    {
        Weight[i] = subtract(Weight[i], multiply(der_Weight[i], step));
        Bias[i] = subtract(Bias[i], multiply(der_Bias[i], step));
    }
}
//输出结果是否正确
inline bool match(const Matrix &res, const Matrix &label)
{
    int max_pos = 0;
    for (int i = 1; i < OUT_SIZE; i++)
        if (res[i][0] > res[max_pos][0])
            max_pos = i;
    return label[max_pos][0] == 1;
}
//检查有无错误样本
inline bool mistake(void)
{
    for (int i = 0; i < NUM_TRAIN; i++)
    {
        const Point &point = TrainData[i];
        forwardPropagation(point);
        if (!match(activation[LAYER_NUM - 1], point.label))
            return true;
    }
    return false;
}
//评估学习率
inline double evaluateStudy(void)
{
    int cnt = 0;
    for (int i = 0; i < NUM_TRAIN; i++)
    {
        const Point &point = TrainData[i];
        forwardPropagation(point);
        if (match(activation[LAYER_NUM - 1], point.label))
            cnt++;
    }
    return (double)cnt / NUM_TRAIN;
}
//评估范化效率
inline double evaluateModel(void)
{
    int cnt = 0;
    for (int i = 0; i < NUM_TEST; i++)
    {
        const Point &point = TestData[i];
        forwardPropagation(point);
        if (match(activation[LAYER_NUM - 1], point.label))
            cnt++;
    }
    return (double)cnt / NUM_TEST;
}
//输出参数
inline void showParameter(void)
{
    cout << "权重: " << endl;
    for (int i = 1; i < LAYER_NUM; i++)
        printMatrix(Weight[i]);
    cout << "偏移量: " << endl;
    for (int i = 1; i < LAYER_NUM; i++)
        printMatrix(Bias[i]);
}
int main(void)
{
    freopen("out.txt", "w", stdout);
    clock_t start_time = clock();
    {
        readALLData(TrainData, TestData);
        Normalize(TrainData);
        Normalize(TestData);
        initialize();
        cout << "--------初始化参数--------" << endl;
        cout << "学习率: " << step << endl;
        showParameter();
        cout << "--------初始化参数--------" << endl
             << endl;
        int i = 0;
        while (i < iteration && mistake())
        {
            try
            {
                zeroClear(der_Weight);
                zeroClear(der_Bias);
                for (int j = 0; j < NUM_TRAIN; j++)
                {
                    forwardPropagation(TrainData[j]);
                    backPropagation(TrainData[j]);
                    accumulateDerivate();
                }
                calculateDerivate();

                gradientDescent();
            }
            catch (char const *message)
            {
                cout << message << endl;
            }
            i++;
        }
        //输出结果
        cout << "--------模型评估--------" << endl;
        cout << "迭代次数: " << i << endl;
        cout << "训练样本量: " << NUM_TRAIN << endl;
        cout << "学习率: " << evaluateStudy() << endl;
        cout << "测试样本量: " << NUM_TEST << endl;
        cout << "范化效率: " << evaluateModel() << endl;
        cout << "参数:" << endl;
        showParameter();
        cout << "--------模型评估--------" << endl
             << endl;
    }
    clock_t end_time = clock();
    cout << "--------时间--------" << endl;
    cout << "耗时: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << 's' << endl;
    cout << "--------时间--------" << endl
         << endl;
    return 0;
}
