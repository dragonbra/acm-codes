#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <random>
using namespace std;

void ShowBiTreeMenu() {
    cout<<"\n";
    cout<<"  ***************《二叉树》****************\n";
    cout<<"  *  1 创建二叉树         2 先序遍历二叉树  *\n";
    cout<<"  *  3 中序序遍历二叉树    4 后序遍历二叉树   *\n";
    cout<<"  *  5 计算树的深度       6 退出           *\n";
    cout<<"  *****************************************\n";
}

const int Max=100000;
int dpt_MX = 0;

struct node {
    int data; int depth;
    node *leftchild;
    node *rightchild;
} *root = NULL;

node *newNode(int v) {
    node *Node=new node;
    Node->data=v;
    Node->leftchild=Node->rightchild=NULL;
    return Node;
}

void insert(node* &root, int x, int dpt) {
    if(root==NULL){
        root=newNode(x);
        root->depth = dpt; dpt_MX = max(dpt_MX, dpt);
        return;
    }
    else if(x<root->data)
        insert(root->leftchild, x, dpt+1);
    else if(x>root->data)
        insert(root->rightchild, x, dpt+1);
}


void CreateBiTree() {
    for (int i=1; i<=5; i++) insert(root, rand()%20, 1);
}

void Preorder(node *root) {
    cout << root->data << ' ';
    if(root->leftchild!=NULL){
        Preorder(root->leftchild);
    }
    if(root->rightchild!=NULL)
        Preorder(root->rightchild);
}

void Inorder(node *root) {
    if(root->leftchild!=NULL){
        Inorder(root->leftchild);
    }
    cout << root->data << ' ';
    if(root->rightchild!=NULL)
        Inorder(root->rightchild);
}

void Postorder(node *root) {
    if(root->leftchild!=NULL){
        Postorder(root->leftchild);
    }
    if(root->rightchild!=NULL)
        Postorder(root->rightchild);
    cout << root->data << ' ';
}

void Depth() {
    cout << "树的深度是" << dpt_MX << endl;
}

int main() {
    int n; srand(unsigned(time(NULL)));
    do{
        ShowBiTreeMenu();
        printf("请选择：");  
        cin>>n;
        switch(n){
            case 1:
                CreateBiTree();break;
            case 2:
                Preorder(root); cout << endl; break;
            case 3:
                Inorder(root); cout << endl; break;
            case 4:
                Postorder(root); cout << endl; break;
            case 5:
                Depth(); break;
            default:
                printf("ERROR!");break;
            }
    }while(n!=6);
}
