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
	LinkList V[MAX];
	int vexnum;
 	int arcnum;
	int visit[MAX];
  	int Queue[MAX];	
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
void SixDegree_BFS(ALGragh G)
{
	for(int j=1;j<=G.vexnum;j++)
	{
		int Visit_Num=1;
		int front=0,rear=0,last=0;
		for(int i=1;i<=G.vexnum;i++)
			G.visit[i]=0;
		G.Queue[0]=j;
		G.visit[j]=1;
		int js=0;
		while(front<=last)
		{
			LinkList p=G.V[G.Queue[front++]]->next;
			while(p)
			{
				if(!G.visit[p->data])
				{
					G.visit[p->data]=1;
					Visit_Num++;
					G.Queue[++rear]=p->data;
				}
				p=p->next;
			}
			if(front>last)
			{
				last=rear;
				js++;
				if(js==6)
					break;
			}
		}
		printf("%d: %.2f%%\n",j,100.0*Visit_Num/G.vexnum);
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
		ALGragh G;
		CreateUDN(G,n,m);
		SixDegree_BFS(G);
	}
	return 0;
} 
