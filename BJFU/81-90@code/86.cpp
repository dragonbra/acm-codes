#include<iostream>
using namespace std;
int c[100];
int flag;
int k;
typedef struct BSTNode
{
	int data;
	struct BSTNode *lchild;
	struct BSTNode *rchild;
}BSTNode,*BSTree;
void Insert(BSTree &T,int e)
{
	if(!T)
	{
		T=new BSTNode;
		T->data=e;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else
	{
		if(e<T->data)
			Insert(T->lchild,e);
		else
			Insert(T->rchild,e);
	}
}
void InOrderTraverse(BSTree T,int n,int key)
{
	if(T)
	{
		InOrderTraverse(T->lchild,n,key);
		c[++k]=T->data;
		if(c[k]>=key)
		{
			if(flag==0)
			{
				cout<<c[k];
				flag=1;
			}
			else
				cout<<" "<<c[k];
		}
      	InOrderTraverse(T->rchild,n,key);
	}
}
int main()
{
	int n,e,key;;
	while(cin>>n&&n!=0)
	{		
		BSTree T=NULL;
		for(int i=0;i<n;i++)
		{
			cin>>e;
			Insert(T,e);
		}
		cin>>key;
		flag=0;
		InOrderTraverse(T,n,key);
		cout<<endl;
	}
	return 0;
}
