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

int Width(BiTree T)
{
	if(T==NULL)
		return 0;
 	BiTree Q[100];
  	int front=1,rear=1,last=1,width=0,WidthMax=0;
	Q[rear]=T;	
	while(front<=last)
	{
      	width++;
		BiTree P=Q[front++];
		if(P->lchild)		
			Q[++rear]=P->lchild;
		if(P->rchild)
			Q[++rear]=P->rchild;
		if(front>last)
		{
			last=rear;
			WidthMax=WidthMax>width?WidthMax:width;
			width=0;
		}
	}
  	return WidthMax;
}

int main()
{
	char S[100];
	while(cin>>S&&S[0]!='0')
	{
		int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		cout<<Width(T)<<endl;
	}
	return 0;
}
