#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int N = 2e5 + 10;
const int MAXSIZE_ = 20;

void ShowLinkMenu()
{
    cout<<"\n";
    cout<<"  ************《链表》*************\n";
    cout<<"  *  1 创建线性表  2 插入元素       *\n";
    cout<<"  *  3 查找元素    4 删除元素       *\n";
    cout<<"  *  5 浏览        6 退出           *\n";
    cout<<"  ***********************************\n";
}

struct MyList
{
	int *data;//起始位置
	int listSize;//最大容量
	int length;//当前长度
} L;

void CreateList() {
	L.listSize = MAXSIZE_;
	L.data = new int[L.listSize];
 	L.length = 0;
    for (int i = 0; i < 10; i++) {
		L.data[i] = i;
		L.length++;
	}
}

void InsertList() {
    cout << "请输入要插入的元素：";
    int x; cin >> x;
    L.data[L.length++] = x;
}

void SearchList() {
    cout << "请输入要查找的元素：";
    int x; cin >> x;

    bool f = false;
    for (int i=0; i<L.length; i++) {
        if (L.data[i] == x) {
            f = true;
            cout << "第" << i << "个" << endl; break;
        }
    }

    if (!f) cout << "未找到" << endl;
}

void DeleteList() {
    cout << "请输入要删除的元素：" << endl;
    int x; cin >> x;

    bool f = false;
    for (int i=0; i<L.length; i++) {
        if (L.data[i] == x) {
            f = true;
            for (int j=i; j<L.length+1; j++) {
                L.data[j] = L.data[j+1];
            }
            L.length--;
            break;
        }
    }

    if (!f) cout << "未找到" << endl;
}

void ShowList() {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    int n;
    do{
        ShowLinkMenu();
        printf("请选择：");
        cin>>n;
        switch(n){
            case 1:
                CreateList();break;
            case 2:
                InsertList();break;
            case 3:
                SearchList();break;
            case 4:
                DeleteList();break;
            case 5:
                ShowList();break;
            case 6: break;

            default:
                printf("ERROR!");break;
        }
    } while(n!=6);
}
