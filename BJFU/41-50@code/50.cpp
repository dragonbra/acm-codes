#include<iostream>
#include<iomanip>
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

double GetAverage(LinkList p ,int n)
{
	if(!p->next)
    	return p->data;
	else
	{
	   double ave=GetAverage(p->next,n-1);
	   return (ave*(n-1)+p->data)/n;
	}
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
    {
      	LinkList L;
		InitList_L(L);
		Input_L(L,n);
		L=L->next;
		cout<<fixed<<setprecision(2)<<GetAverage(L,n)<<endl;
	}
	return 0;                
}
