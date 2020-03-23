#include<iostream>
using namespace std;
#define MAXSIZE 100            
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void InitList(LinkList &L)
{
    L=new LNode;
    L->next=NULL;
}
void CreateList(LinkList &L,int n)
{
 	LinkList q=L;
    for(int i=0;i<n;i++)
	{	
		LinkList p=new LNode;         
		cin>>p->data;            
		p->next=NULL;
		q->next=p;
		q=p;
	}
}
void SortList(LinkList &L,int n)
{	
	for(int j=0;j<n;j++)
	{
		LinkList p=L->next; 
		for(int i=0;i<n-1;i++)
		{	
			if(p->data>p->next->data)
			{
				int t;
				t=p->data;
				p->data=p->next->data;
				p->next->data=t;
			}
			p=p->next;
		}
	}
}
void PrintList(LinkList L,int n)
{
	LinkList p=L->next;
	for(int i=0;i<n-1;i++)
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
		InitList(L);
		CreateList(L,n);
		SortList(L,n);
		PrintList(L,n);      
	}
	return 0;                
}
