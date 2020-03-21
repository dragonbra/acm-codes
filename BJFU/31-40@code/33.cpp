#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2         

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList; 

int Abs(int x)
{ 
	return x>0?x:-x;
}

int InitList_L(LinkList &L,int n)			
{
	L=new LNode;
	L->data=-1;
	L->next=NULL;
	LinkList p,r=L;
	while(n--)
	{
		p=new LNode;
		cin>>p->data;
		if(Abs(p->data)>L->data)
			L->data=Abs(p->data);
		p->next=r->next;
		r->next=p;
		r=p;
	}
	return OK;
}

int Delete_L(LinkList &L)
{
	int f[1000];
	for(int i=0;i<L->data+1;i++)
		f[i]=0;	
  	LinkList p=L,q;
	while(p->next)
	{
		if(f[Abs(p->next->data)])
		{
			q=p->next;
			p->next=q->next;
			delete(q);
		}
		else
		{
			f[Abs(p->next->data)]=1;
			p=p->next;
		}
	}
  	p=L->next;
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
	LinkList L,p;
	int n;
	while(cin>>n&&n!=0)
	{
		InitList_L(L,n);
		Delete_L(L);
	}
	return 0;
}
