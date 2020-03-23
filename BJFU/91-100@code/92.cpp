#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
	struct LNode *prior;
}LNode,*LinkList;
void InitList(LinkList &L,int n)
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
		p->prior=L;
		L=p;
	}
	L=H;
}
void Sort(LinkList &L)
{
	LinkList p=L->next;
	while(p->next)
		p=p->next;
	LinkList last=p;	
	LinkList first=L->next;
	while(1)
	{
		if(first!=last)
		{	
			for(p=first;p!=last;p=p->next)
				if(p->data>p->next->data)
				{
					int t=p->data;
					p->data=p->next->data;
					p->next->data=t;
				}
			last=last->prior;
		}
		else
			break;
		if(first!=last)
		{
			for(p=last;p!=first;p=p->prior)
				if(p->data<p->prior->data)
				{
					int t=p->data;
					p->data=p->prior->data;
					p->prior->data=t;
				}
			first=first->next;
		}
		else
			break;
	}
}
void Print(LinkList L)
{
	LinkList p=L->next;
	while(p->next)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl; 
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{ 	
		LinkList L;
		InitList(L,n);
		Sort(L);
		Print(L);
	}
	return 0;
}
