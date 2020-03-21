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
int InitList_L(LinkList &L1)			
{
    L1=new LNode;			
    L1->next=NULL;
	return OK;
}
int Inverted_L(LinkList &L)		
{
	LinkList H=L;
	int i,n;
	while(cin>>n&&n!=0)			
	{
		L=H;
		for(i=0;i<n;i++)
		{
			LinkList p=new LNode;		
			cin>>p->data;
			p->next=NULL;
			L->next=p;
			L=p;		
		}
		L=H;
		LinkList s=L->next,t=NULL;	
		while(s)
		{ 
			t=s;                 
			s=s->next;          
			t->next=H;             
			H=t;                    
		}
		L->next=NULL;                      
		L=H;
		while(L->next->next)
		{
			cout<<L->data<<" ";	
			L=L->next;
		}
		cout<<L->data<<endl;	
		L=H;
	}
	return OK;
}
int main()
{
    LinkList L;
    InitList_L(L);
    Inverted_L(L);					
    return 0;                
}
