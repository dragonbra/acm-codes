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
	struct LNode *prior;
}LNode,*LinkList;

int InitList_L(LinkList &L,int n)
{
  	L=new LNode;	
	L->next=NULL;
	LinkList H=L;
	L->prior=L;
	L->next=L;
	while(n--)
	{
		LinkList p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
		p->prior=L;
		p->next->prior=p;
		L=p;
	}
	L=H;
	return OK;
}

void Exchange(LinkList &L,int key)
{
	LinkList p=L;
	while(key--)
		p=p->next;
	p->prior->next=p->next;
	p->prior->prior->next=p;
	p->next=p->prior;
	p->prior=p->prior->prior;
	p->next->prior=p;
	p->next->next->prior=p->next;
	p=L->next;
	while(p->next&&p->next!=L)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl; 
}

int main()
{
	int n,key;
	LinkList L;
	while(cin>>n&&n!=0)
	{
	 	InitList_L(L,n);
		cin>>key;
		if(n==1)
		{
			cout<<L->next->data<<endl;
			continue;
		}
		Exchange(L,key);
	}
	return 0;
}
