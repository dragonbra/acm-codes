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

int InitList_L(LinkList &L)			
{
    L=new LNode;			
    L->next=NULL;
    return OK;
}

int MergeList_L(LinkList &L1,LinkList &L2)
{
	LinkList H1=L1,H2=L2;
	int i,n,m;
	while(cin>>n>>m&&n!=0&&m!=0)	
	{
		for(i=0;i<n;i++)
		{
			LinkList p=new LNode;		
			cin>>p->data;
			p->next=NULL;
			L1->next=p;
			L1=p;		
		}
		L1=H1;
		for(i=0;i<m;i++)
		{
			LinkList p=new LNode;		
			cin>>p->data;
			p->next=NULL;
			L2->next=p;
			L2=p;		
		}
		L2=H2;

 		LinkList p1,p2,p3;
		p1=L1->next;
		p2=L2->next;
      	p3=L1;

		while(p1&&p2)
		{
			if(p1->data<p2->data)
			{
				p3->next=p1;
				p3=p3->next;
				p1=p1->next;
			}
			else if(p2->data==p1->data)
			{
				p3->next=p1;
				p3=p3->next;
				p1=p1->next;
				p2=p2->next;
			}
			else
			{	
				p3->next=p2;
				p3=p3->next;
				p2=p2->next;
			}
		}
		p3->next=p1?p1:p2;
		
		while(L1->next->next)		
		{
			cout<<L1->next->data<<" "; 
			L1=L1->next;
		}
		cout<<L1->next->data<<endl;
		L1=H1;
	}
	return OK;
}

int main()
{
	LinkList L1,L2;
    InitList_L(L1);
  	InitList_L(L2);
    MergeList_L(L1,L2);		
    return 0;                
}
