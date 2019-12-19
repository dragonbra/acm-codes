#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll INF=LONG_LONG_MAX;
const int N=1e3+5; 
int n,m,S,T,k;
struct edge { int v,w; };
vector<edge> G[N];
struct node{
	int u,dis;
	node() {}
	node(int u,int dis):u(u),dis(dis) {}
	bool operator <(const node &rhs) const {
		return dis>rhs.dis;
	}
};
int dis[N][N];
bool vis[N];
priority_queue<node> q;
void solve() {
//	cout<<S<<endl; 
	q.push({S,dis[S][k]});
	while(!q.empty()) {
		node cur=q.top();
		q.pop();
		int u=cur.u; 
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v;int w=G[u][i].w;
			for(int j=0;j<=k;j++) {
				if(dis[v][j]>dis[u][j]+w) {
					dis[v][j]=dis[u][j]+w;
					q.push({v,dis[v][j]});
				}
			}
			for(int j=0;j<k;j++) {
				if(dis[v][j]>dis[u][j+1]) {
					dis[v][j]=dis[u][j+1];
					q.push({v,dis[v][j]}); 
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d%d",&n,&m,&S,&T,&k);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++) 
		for(int j=0;j<=k;j++)
			dis[i][j]=inf;
	dis[S][k]=0;
	solve();
	int ans=2e9;
	for(int i=0;i<=k;i++) 
		cout<<dis[T][i]<<endl;
	printf("%d\n",ans);
	return 0;
}
