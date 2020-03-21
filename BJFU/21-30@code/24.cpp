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
int Thesame_L(LinkList &L1,LinkList &L2)
{
	LinkList p,p1=L1->next,p2=L2->next,p3=L1;
	while(p1&&p2)
	{
		if(p2->data==p1->data)
		{
          	p3->next=p1;
			p3=p1;
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->data<p2->data)
			p1=p1->next;
		else
			p2=p2->next;
	}
	p3->next=NULL;
	while(p1)
		p1=p1->next;
	while(p2)
		p2=p2->next;
  	p=L1->next;
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
	int n,m;
	LinkList L1,L2;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
		InitList_L(L1,n);
		InitList_L(L2,m);
		Thesame_L(L1,L2);
	}
	return 0;
}
