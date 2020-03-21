#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct LNode
{
	char data;
	struct LNode *next;
}LNode,*LinkList;

int InitList_L(LinkList &L,int n)
{
	L=new LNode;
	L->next=NULL;
	LinkList p,H=L;
	while(n--)
	{
		p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
	L=H;
 	return OK;
}

void Find_L(LinkList L1,LinkList L2)
{
	LinkList H1=L1,H2=L2;
	while(L1->next&&L2->next)
	{
		if(L1->next->data==L2->next->data)
		{
			L1=L1->next;
			L2=L2->next;
		}
		else
		{
			cout<<L1->data<<endl;
			return;		
		}
	}
	cout<<L1->data<<endl;
}

int main()
{
	LinkList L1,L2;
	int n,m;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
		InitList_L(L1,n);
		InitList_L(L2,m);
		Find_L(L1,L2);
	}
	return 0;
}
