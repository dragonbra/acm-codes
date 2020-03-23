#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList H[13];
void Hash(int e)
{
	int index=e%13;		
	LinkList p=H[index];
	while(p->next)
		p=p->next;
	LinkList q=new LNode;
	q->data=e;
	q->next=NULL;
	p->next=q;
} 
void Input(int n)
{
	for(int i=0;i<13;i++)
	{
		H[i]=new LNode;
		H[i]->next=NULL;
	}
	while(n--)
	{
		int e;
		cin>>e;
		Hash(e);
	}
}
void Delete(int e)
{
	int index=e%13;
	LinkList p=H[index];
	while(p->next)
	{
		if(p->next->data==e)
			break;
		p=p->next;
	}
	if(p->next!=NULL)
		p->next=p->next->next;
}
void Output()
{
	for(int i=0;i<13;i++)
	{
		cout<<i;
		LinkList p=H[i]->next;
		while(p)
		{
			cout<<" "<<p->data;
			p=p->next;
		}
		cout<<endl;
	}
}
int main()
{
	int n;	
	while(cin>>n&&n!=0)
	{
		int e;
		Input(n);
		cin>>e;
		Delete(e);
		Output();
	}
	return 0;
}
