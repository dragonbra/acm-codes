
// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round #20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
// Memory Limit: 64 MB
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

typedef long long ll;
const ll INF = 1e18;
const int N = 2e5 + 10;

int n, m;
struct edge {
	int v; ll w;
	edge(int v, ll w):v(v), w(w){}
};
vector<edge> G[N];
struct node {
	int u; ll dis;
	node(int u, ll dis):u(u), dis(dis){}
	friend bool operator<(node a, node b) {
		return a.dis > b.dis;
	}
};
ll dis[N];
ll f[N];
bool vis[N];
int ans[N];

void init() {
	for (int i=1; i<=n; i++) {
		dis[i] = INF;
		vis[i] = false;
	}
}

int main() {

    fastio;
    cin >> n >> m;
    
    init();
    
    for (int i=1; i<=m; i++) {
    	int u, v; ll w;
    	cin >> u >> v >> w;
    	G[u].push_back(edge(v, w));
    	G[v].push_back(edge(u, w));
    }
    
    priority_queue<node> Q; Q.push(node(1, 0)); dis[1] = 0;
	while (!Q.empty()) {
		node now = Q.top(); Q.pop();
		int u = now.u; ll d = now.dis;
		if (vis[u]) continue;
		vis[u] = true;
		// cout << u << ' ' << d << endl;
		for (auto nxt: G[u]) {
			int v = nxt.v; ll w = nxt.w;
			if (d + w < dis[v]) {
				dis[v] = d + w;
				f[v] = u;
				Q.push(node(v, dis[v]));
			}
		}
	}
	
	int cnt = 0; int x = n;
	while (x != 1) {
		if (f[x] == 0) break;
		ans[++cnt] = x;
		x = f[x];
	}
	if (cnt == 0) {
		puts("-1");
	} else {
		ans[++cnt] = 1;
		for (int i=cnt; i>=1; i--) {
			cout << ans[i] << ' ';
		}
	}
	
    return 0;
}
