#include<iostream>
using namespace std;
int flag;

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

void Compare(BiTree T1,BiTree T2)
{
	if((T1&&!T2)||(!T1&&T2))
		flag=0;
	if(T1&&T2)
	{
    	if(T1->data!=T2->data)
			flag=0;
		Compare(T1->lchild,T2->lchild);
		Compare(T1->rchild,T2->rchild);
	}
}

int main()
{
	char S1[100],S2[100];
	while(cin>>S1&&S1[0]!='0')
	{
		cin>>S2;
		int i=-1,j=-1;
	  	BiTree T1,T2;
		CreateBiTree(T1,S1,++i);
		CreateBiTree(T2,S2,++j);
		flag=1;
		Compare(T1,T2);
		if(flag==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
