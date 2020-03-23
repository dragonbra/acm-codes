#include<iostream>
using namespace std;
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
int Depth(BiTree T)
{
	if(!T)
		return 0;
	else if(!T->lchild&&!T->rchild)
		return 1;
	return Depth(T->lchild)>=Depth(T->rchild)?Depth(T->lchild)+1:Depth(T->rchild)+1;
}
int main()
{
	char S[200];
	while(cin>>S&&S[0]!='#')
	{
		int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		cout<<Depth(T)<<endl;
	}
	return 0;
}
