#include<iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define MAX 100
typedef struct AMGragh 
{
	int vexnum;
 	int arcnum;
	int vexs[MAX][MAX];
}AMGragh;
int CreateUDN(AMGragh &G,int vexnum,int arcnum)
{
	G.vexnum=vexnum;
	G.arcnum=arcnum;
	if(G.vexnum>MAX)
    	return ERROR;
  	for(int i=0;i<=G.vexnum;i++)
		G.vexs[0][i]=G.vexs[i][0]=i;
    for(int i=1;i<=G.vexnum;i++)
		for(int j=1;j<=G.vexnum;j++)
			G.vexs[i][j]=0;
	int h,k;
    for(int i=1;i<=G.arcnum;i++)
    {
      cin>>h>>k;
      G.vexs[h][k]=G.vexs[k][h]=1;
    }
	return OK;
}
int DeleteArc(AMGragh &G)
{
  	int x,y;
	cin>>x>>y;
	G.vexs[x][y]=G.vexs[y][x]=0;
	G.arcnum--;
	return OK;  
}
int OutputUDN(AMGragh G)
{
	for(int i=0;i<=G.vexnum;i++)
	{
		for(int j=0;j<G.vexnum;j++)
          cout<<G.vexs[i][j]<<" ";	
		cout<<G.vexs[i][G.vexnum]<<endl;	
	}
	return OK;
}
int main()
{
	int n,m;
	while(cin>>n>>m&&m!=0&&n!=0)
	{
		AMGragh G;
      	CreateUDN(G,n,m);
      	DeleteArc(G);
      	OutputUDN(G);
	}
	return 0;	
}
