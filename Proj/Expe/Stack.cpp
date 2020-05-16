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
const int maxx=1e5;

template <class T>

class stack{
    public:
        T stk[maxx];
        int top;
        stack(){
            top=0;
        }
        bool stackfull();
        bool stacknull();
        void push(T x);
        T pop();
};

template <class T>
bool stack<T>::stackfull(){
    if(top==maxx-1) return 1;
    return 0;
}

template <class T>
bool stack<T>::stacknull(){
    if(top==0)  return 1;
    return 0;
}

template <class T>
T stack<T>::pop(){
    if(stacknull())  return 1;
    return stk[--top];
}

template <class T>
void stack<T>::push(T x){
    if(stackfull())  return ;
    stk[top++]=x;
}

void ShowStackMenu() {
    cout<<"\n";
    cout<<"  **************《栈》***************\n";
    cout<<"  *  1 创建栈         2 数据元素入栈  *\n";
    cout<<"  *  3 数据元素出栈   4 取栈顶元素    *\n";
    cout<<"  *  5 退出                          *\n";
    cout<<"  ***********************************\n";
}

stack<int> S;

void CreateStack() {
    for (int i=1; i<=5; i++) S.push(i);
}

void PushStack() {
    cout << "请输入要入栈元素" << endl;
    int x; cin >> x;
    S.push(x);
}

void PopStack() {
    int x = S.pop();
    cout << "元素" << x << "已出栈" << endl;
}

void GetTop() {
    int x = S.pop();
    S.push(x);
    cout << "栈顶元素是" << x << endl;
}

int main() {
    int n;
    do{
        ShowStackMenu();
        printf("请选择：");
        cin>>n;
        switch(n){
            case 1:
                CreateStack();break;
            case 2:
                PushStack();break;
            case 3:
                PopStack();break;
            case 4:
                GetTop();break;
            case 5:break;
            default:
            printf("ERROR!");break;
        }
    } while(n!=5);
}
