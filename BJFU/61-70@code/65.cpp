#include<iostream>
using namespace std;
char path[100];

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

void DFS(BiTree T,int n)
{
	if(T)
	{
		path[n]=T->data;
		if(!T->lchild&&!T->rchild)
		{
			for(int i=n;i>=1;i--)
				cout<<path[i];
			cout<<endl;
		}
		else
		{
			DFS(T->lchild,n+1);
			DFS(T->rchild,n+1);
		}
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
		int n=0;
		DFS(T,n+1);
	}  
	return 0;
}
