#include<iostream>
using namespace std;
int flag;
char c[100];
int k;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{
	if(S[i]=='#')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=S[i];
		CreateBiTree(T->lchild,S,++i);
		CreateBiTree(T->rchild,S,++i);
	}
}
void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		c[++k]=T->data;
      	if(k>1&&c[k-1]>T->data)
        { 	
          	flag=0;
        	return;
        }
		InOrderTraverse(T->rchild);
	}
}
int main()
{
	char S[100];
	while(cin>>S&&S[0]!='#')
	{
		int i=-1;
		flag=1;
		k=0;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		InOrderTraverse(T);
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

