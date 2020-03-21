#include<iostream>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

int InitList_L(LinkList &L,int n)
{
  	L=new LNode;	
	L->next=NULL;
	LinkList H=L;
	while(n--)
	{
		LinkList p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
		L=p;
	}
	L=H;
	return OK;
}

int Divide_L(LinkList &L,LinkList &L1,LinkList &L2)
{
 	L1=new LNode;
	L1->next=NULL;
	L2=new LNode;
	L2->next=NULL;
	LinkList p=L->next,p1=L1,p2=L2;
	while(p)
	{
		if(p->data>0)
		{
			p2->next=p;
			p2=p;
			p=p->next;
		}
		else if(p->data==0)
			p=p->next;
		else
		{
			p1->next=p;
			p1=p;
			p=p->next;	
		}
	}
	
	p1->next=NULL;
	p2->next=NULL;

	p=L1->next;
	while(p->next)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;

	p=L2->next;
	while(p->next)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
	return OK; 
}

int main()
{
	int n;
	LinkList L,L1,L2;
	while(cin>>n&&n!=0)
	{
		InitList_L(L,n);
		Divide_L(L,L1,L2);
	}
	return 0;
}
