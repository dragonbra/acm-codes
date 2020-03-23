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
int DFS_AL(ALGragh G)
{
	int d,top=0,visit[MAX],Stack[MAX];
	for(int i=0;i<MAX;i++)
		visit[i]=0;
	cin>>d;
	cout<<d;
	Stack[top++]=d;
	visit[d]=1;
	while(top>0)
	{
		int t=-1;
		LinkList p=G.V[Stack[top-1]];	
		while(p)
		{
			if(!visit[p->data])
				t=p->data;
			p=p->next;
		}
		if(t==-1)
			top--;
		else
		{
			cout<<" "<<t;
			Stack[top++]=t;
			visit[t]=1;
		}
	}
	cout<<endl;
	return OK;
}
int main()
{
	int n,m;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
		ALGragh G;
       	CreateUDN(G,n,m);
   		DFS_AL(G);
	}
	return 0;
}
