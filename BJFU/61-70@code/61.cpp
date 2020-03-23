#include<iostream>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T,char S[],int &i)
{
	if(S[i]=='0')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=S[i];
		CreateBiTree(T->lchild,S,++i);
		CreateBiTree(T->rchild,S,++i);
	}
}

void ChangeRL(BiTree &T)
{
	if(T&&(T->lchild||T->rchild))
	{
		BiTree t=new BiTNode;
		t=T->lchild;
		T->lchild=T->rchild;
		T->rchild=t;
		ChangeRL(T->lchild);
		ChangeRL(T->rchild);
	}
}

void PreOrderTraverse(BiTree T)
{
	if(T)
	{
    	cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

int main()
{
	char S[100];
	while(cin>>S&&S[0]!='0')
	{
		int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		ChangeRL(T);
		PreOrderTraverse(T);	
		cout<<endl;
	}
	return 0;
}
