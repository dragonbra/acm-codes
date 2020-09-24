/**
 * main.cpp 
 */
#include <iostream>
#include <cstdio>
#include "huffman.h"
using namespace std;

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }
    if (x == 1) {
        string in, out;
        cout << "请输入压缩的源文件名：" << endl;
        cin >> in;
        cout << "请输入压缩的输出文件名：" << endl;
        cin >> out;

        Huffman h(in, out);
        h.compress();

        cout << endl;
        cout << "----压缩完成!" << endl;
        cout << endl;
    } else if (x == 2) {
        string in, out;
        cout << "请输入解压的源文件名：" << endl;
        cin >> in;
        cout << "请输入解压的输出文件名：" << endl;
        cin >> out;

        Huffman h(in, out);
        h.decompress();

        cout << endl;
        cout << "----解压完成!" << endl;
        cout << endl;
    } else if (x == 3) {
        char in[110], out[110];
        cout << "请输入文件名-1：" << endl;
        cin >> in;
        cout << "请输入文件名-2：" << endl;
        cin >> out;

        FILE* file = fopen(in, "rb");  
        fseek(file,0,SEEK_END);  //先用fseek将文件指针移到文件末尾
        int size1 = ftell(file);    //再用ftell获取文件内指针当前的文件位置。
        //这个位置就是文件大小。
        FILE* file_2 = fopen(out, "rb");
        fseek(file_2, 0, SEEK_END);
        int size2 = ftell(file_2);

        cout << endl;
        cout << "文件-1：" << in << " 的大小为 " << size1 << " 字节" << endl;
        cout << "文件-2：" << out << " 的大小为 " << size2 << " 字节" << endl;
        cout << endl;
        cout << "（因为压缩后文件中头部存储哈夫曼树，在压缩文件较小的情况下可能会出现文件体积增大）" << endl;
    } else if (x == 4) {
        //选择退出
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用Huffman编码压缩/解压文件        \n");
    printf("|       输入以选择：                          \n");
    printf("|       1. 压缩文件                          \n");
    printf("|       2. 解压文件                          \n");
    printf("|       3. 对比文件大小                       \n");
    printf("|       4. 退出                              \n");
    printf("---------------------------------------------\n");

    choose();
}

int main(int argc, char *argv[]) {
    while (true) {
        printMenu();
    }
}
