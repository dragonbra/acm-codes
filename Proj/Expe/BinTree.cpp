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

void ShowBiTreeMenu()
{
cout<<"\n";
cout<<"  ***************《二叉树》****************\n";
cout<<"  *  1 创建二叉树         2 先序遍历二叉树  *\n";
cout<<"  *  3 中序序遍历二叉树   4后序遍历二叉树   *\n";
cout<<"  *  5 计算树的深度       6 退出           *\n";
cout<<"  *****************************************\n";
}
int main() {
    int n;
    do{
        ShowBiTreeMenu();
        printf("请选择：");  
        cin>>n;
        switch(n){
            case 1:
                CreateBiTree();break;
            case 2:
                Preorder();break;
            case 3:
                Inorder();break;
            case 4:
                Postorder();break;
            case 5:
            Depth()break;
            default:
            printf("ERROR!");break;
            }
    }while(n!=6);
}
