#include<iostream>
using namespace std;
int number;				

typedef struct BiTNode
{
	int data;
	int count;
	struct BiTNode *llink;
	struct BiTNode *rlink;
}BiTNode,*BiTree;

void aInOrderTraverse(BiTree T,int &N)		
{
	if(T)
	{
		aInOrderTraverse(T->llink,N);
		cout<<T->data;
		if(++number<N)						
			cout<<" ";
		else								
			cout<<endl;
		aInOrderTraverse(T->rlink,N);
	}
}

void bInOrderTraverse(BiTree T,int &N)		
{
	if(T)
	{
		bInOrderTraverse(T->llink,N);
		cout<<T->count;
		if(++number<N)						
			cout<<" ";
		else
			cout<<endl;						
		bInOrderTraverse(T->rlink,N);
	}
}

void SearchBST(BiTree &T,int key,int &N)
{
	BiTree s=new BiTNode;					
	s->data=key;
	s->count=0;
	s->llink=NULL;
	s->rlink=NULL;
	if(!T)									
	{
		T=s;
		return;
	}
	BiTree q=T,p;						
	while(q)								
	{
		if(q->data==key)					
		{
			q->count++;
			return;							
		}
		p=q;								
		if(q->data>key)						
			q=q->llink;
		else 								
			q=q->rlink;
	}
	if(p->data>key)							
	{
		N++;								
		p->llink=s;	
	}
	else
	{
		N++;
		p->rlink=s;
	}
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int N=1,S[100];
	  	BiTree T=NULL;	
		for(int j=0;j<n;j++)
		{	
			cin>>S[j];
			SearchBST(T,S[j],N);
		}
		int key;
		cin>>key;
		SearchBST(T,key,N);
		number=0;				
		aInOrderTraverse(T,N);
		number=0;				
		bInOrderTraverse(T,N);
	}
	return 0;
}
