
// Problem: P3387 【模板】缩点
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3387
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
  @ author: dragon_bra
  @ QQ: 1277037638
  @ email: tommy514@foxmail.com
*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int N = 10000+15;
int n, m;
vector<int> G[N];
vector<int> G2[N];
int tim, top;
int p[N], belong[N], dfn[N], low[N];
//DFN(u)为节点u搜索被搜索到时的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号 
int stac[N], vis[N];
//栈只为了表示此时是否有父子关系 
int in[N], dist[N];

void tarjan(int x) {
	// tarjan 缩点核心代码
	low[x]=dfn[x]=++tim;
	stac[++top]=x;vis[x]=1;
	for (int v:G[x]) {
		if (!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		} else if (vis[v]) {
	    	low[x] = min(low[x], low[v]);
		}
	}
	if (dfn[x]==low[x]) {
		int y;
		while (y=stac[top--]) {
			belong[y] = x;
			vis[y] = 0;
			if (x==y) break;
			p[x] += p[y]; // 增加点权，本题有效
		}
	}
}

int topo() {
	queue <int> Q;
	for (int i=1; i<=n; i++) {
		if (belong[i]==i && !in[i]) {
			Q.push(i);
	        dist[i] = p[i];
		} 
	}
	 
	while (!Q.empty()) {
		int now = Q.front(); Q.pop();
		for (int v:G2[now]) {
			dist[v] = max(dist[v], dist[now] + p[v]);
			in[v] --;
			if (in[v]==0) Q.push(v);
		}
	}
	
    int ans = 0;
    for (int i=1;i<=n;i++) ans = max(ans, dist[i]);
    
    return ans;
}

int main() {
	fastio;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> p[i];
	
	for (int i=1; i<=m; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}
	
	for (int i=1; i<=n; i++) 
		if (!dfn[i]) tarjan(i);
		
	for (int i=1; i<=n; i++) {
		for (int v:G[i]) {
			if (belong[i] == belong[v]) continue;
			G2[belong[i]].push_back(belong[v]);
			in[belong[v]] ++;
		}
	}
	
	printf("%d",topo());
	
	return 0;
}