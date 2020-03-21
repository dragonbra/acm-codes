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

int InitList_L(LinkList &L,int n)			
{
	L=new LNode;
	L->data=0;
	L->next=NULL;
	LinkList p,H=L;	
	for(int i=1;i<=n;i++)
	{
		p=new LNode;
		p->data=i;
		p->next=L->next;
		L->next=p;
		L=p;
		H->data++;
	}
	L->next=H;				
	L=H;
	return OK;
}

int MonkeyKing_L(LinkList &L,int n)
{
	LinkList H=L,q;
	while(H->data>1)
	{
		for(int i=1;i<n;i++)
		{
			L=L->next;
			if(L==H)		
				L=L->next;
		}
		if(L->next==H)		
			L=L->next;
		cout<<L->next->data<<" ";
		q=L->next;
		L->next=q->next;
		delete(q);
		H->data--;
	}
	cout<<H->next->data<<endl;
	L=H;
	return OK;
}

int main()
{
	LinkList L;
	int m,n;
	while(cin>>m>>n&&m!=0&&n!=0)
	{
		InitList_L(L,m);
		MonkeyKing_L(L,n);
	}
	return 0;
}
