#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int inf = 0x3f3f3f3f;
int n,m,S,T,k;int ans;
int dis[N][N];bool vis[N];
struct edge{
	int v,w;
};
vector<edge> G[N];
struct node{
	int u,dis;
	node(int _u,int _dis):u(_u),dis(_dis) {}
	bool operator < (const node &b) const{
		return dis>b.dis;
	}
};
priority_queue<node> Q;

int main(){
	scanf("%d %d %d %d %d",&n,&m,&S,&T,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			dis[i][j]=inf;
		}
	}
	dis[S][k]=0;
	
	//zuiduanlu
	Q.push({S,0});
	while(!Q.empty()){
		node t=Q.top();Q.pop();
		int u=t.u;
		if(vis[u]) continue;
		vis[u]=1;
		
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v;int w=G[u][i].w;
			for(int j=0;j<=k;j++){
				if(dis[v][j]>dis[u][j]+w){
					dis[v][j]=dis[u][j]+w;
					Q.push({v,dis[v][j]});
				}
			}
			for(int j=0;j<k;j++){
				if(dis[v][j]>dis[u][j+1]){
					dis[v][j]=dis[u][j+1];
					Q.push({v,dis[v][j]}); 
				}
			}
		}
	}
	
	ans=inf;
	for(int i=0;i<=k;i++) ans=min(ans,dis[T][i]);
	printf("%d\n",ans);
	
	return 0;
}
