#include<iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define MAX 100
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
typedef struct
{
	int vexnum;
 	int arcnum;
	LinkList V[MAX];
}ALGragh;
int CreateUDN(ALGragh &G,int vexnum,int arcnum)
{
	G.vexnum=vexnum;
	G.arcnum=arcnum;
	if(G.vexnum>MAX)
    	return ERROR;
  	for(int i=1;i<=vexnum;i++)
	{
		G.V[i]=new LNode;
		G.V[i]->data=i;
		G.V[i]->next=NULL;
	}
  	while(arcnum--)
	{
      	int x,y;
		cin>>x>>y;
      	LinkList p=new LNode;
		p->data=y;
		p->next=G.V[x]->next;	
      	G.V[x]->next=p;	
        LinkList q=new LNode;
		q->data=x;
		q->next=G.V[y]->next;
		G.V[y]->next=q;
	}
  	return OK;
}
int DeleteArc(ALGragh &G)
{
	int i,j;
	cin>>i>>j;
	LinkList q;
  	q=G.V[i];
	while(q->next)
	{
		if(q->next->data==j)
		{
			q->next=q->next->next;
			G.arcnum--;
			break;
		}
		q=q->next;
	}
  	q=G.V[j];
	while(q->next)
	{
		if(q->next->data==i)
		{
			q->next=q->next->next;
			G.arcnum--;
			break;
		}
		q=q->next;
	}
	return OK;
}
int PrintGraph(ALGragh G)
{  
  	for(int i=1;i<=G.vexnum;i++)
    {
		LinkList p=G.V[i];
		while(p->next)
		{
			cout<<p->data<<" "; 
			p=p->next;
		}
		cout<<p->data<<endl; 
    }
    return OK;
}
int main()
{
	int n,m;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
      	ALGragh G;
       	CreateUDN(G,n,m);
     	DeleteArc(G);	
	   	PrintGraph(G);
	}
	return 0;
}
