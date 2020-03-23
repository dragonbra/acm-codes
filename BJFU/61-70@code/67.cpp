#include<iostream>
using namespace std;
int a,b,c;

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

void Count(BiTree T)
{
	if(T)
	{
      	if(T->lchild&&T->rchild)
			c++;
		else if(T->lchild||T->rchild)
			b++;
      	else
			a++;
		Count(T->lchild);
		Count(T->rchild);
	}
}

int main()
{
	char S[100];
	while(cin>>S&&S[0]!='0')
	{
		a=b=c=0;
      	int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		Count(T);
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
