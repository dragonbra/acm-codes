#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int Ni = 10005;
const int INF = 1<<27;
struct node{
	int x,d;
	node(int a,int b):x(a),d(b){}
	bool operator < (const node & a) const
	{
		if(d==a.d) return x<a.x;
		else return d>a.d;
	}
};
vector<node> eg[Ni];
int dis[Ni],n;
void dijkstra(int s)
{
	int i;
	for(i=0;i<=n;i++) dis[i]=INF;
	dis[s]=0;
	priority_queue<node> q;
	q.push(node(s,dis[s]));
	while(!q.empty())
	{
		node x = q.top();q.pop();
		for(i=0;i<eg[x.x].size();i++)
		{
			node y = eg[x.x][i];
			if(dis[y.x]>x.d+y.d)
			{
				dis[y.x]=x.d+y.d;
				q.push(node(y.x,dis[y.x]));
			}
		}
	}
}
int main()
{
	int u,v,w,m,s;
	cin>>n>>m>>s;
	for(int i=0;i<=n;i++) eg[i].clear();
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		eg[u].push_back(node(v,w));
	}
	dijkstra(s);
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==INF)
			printf("2147483647 ");
		else
			printf("%d ",dis[i]);
	}
	return 0;
}