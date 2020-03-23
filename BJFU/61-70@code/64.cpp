#include<iostream>
using namespace std;
int len;
int ans[100];
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
		ans[n]=T->data;
		if(!T->lchild&&!T->rchild)
		{
			if(n+1>len)
			{
				len=n+1;
				for(int i=0;i<=n;i++)
					path[i]=ans[i];
			}
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
		len=0;
		DFS(T,len);
		cout<<len<<endl;
		for(i=0;i<len;i++)
			cout<<path[i];
		cout<<endl;
	}
	return 0;
}
