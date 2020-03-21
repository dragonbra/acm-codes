#include<iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void InitList_L(LinkList &L)		
{
    L=new LNode;
    L->next=NULL;
}

void Input_L(LinkList &L,int n)
{
  	LinkList H=L;
	while(n--)
	{
		LinkList p=new LNode;         	
		cin>>p->data;
		p->next=NULL;
		L->next=p;
		L=p;
	}
  	L=H;                    
}

int Length_L(LinkList L)		
{
	if(L->next==NULL)
		return 0; 
	return 1+Length_L(L->next);                            
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
    {
      	LinkList L;
		InitList_L(L);
		Input_L(L,n);					
		cout<<Length_L(L)<<endl;		
	}
	return 0;                
}
