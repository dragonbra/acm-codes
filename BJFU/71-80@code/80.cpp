#include<iostream>
using namespace std;
#define maxn 200
#define inf 1e9
int n;
int e[maxn][maxn];
int dis[maxn];
int visit[maxn];
void Dijkstra(int s)
{
	int min,k;
	for(int i=1; i<=n; i++)
	{
		dis[i]=e[s][i];
		visit[i]=0;
	}
	dis[s]=0;
	visit[s]=1;
	for(int i=0; i<n-1; i++)
	{
		min=inf;
		for(int i=1; i<=n; i++)
		{
			if(!visit[i] && dis[i]<min)
			{
				min=dis[i];
				k=i;
			}
		}
		visit[k]=1;
		for(int i=1; i<=n; i++)
		{
			if(!visit[i] && dis[i]>dis[k]+e[k][i])
				dis[i]=dis[k]+e[k][i];
		}
	}
}
int main()
{
	int m,s;
	int x,y,d;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				e[i][j]=inf;
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&d);
			e[x][y]=e[y][x]=d;
		}
		cin>>s;
		Dijkstra(s);
		int ans,max=-1;
		for(int i=1; i<=n; i++)
		{
			if(dis[i]>max && dis[i]<inf)
			{
				max=dis[i];
				ans=i;
			}
		}
		cout<<ans<<endl<<max<<endl;
	}
	return 0;
}
