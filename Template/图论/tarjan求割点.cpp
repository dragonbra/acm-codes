
// Problem: P3388 【模板】割点（割顶）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3388
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

const int N = 2e5 + 10;

int n,m;
struct edge {
	int next,to;
} p[N];

int head[N], num; // num stands for edge number

void addEdge(int x,int y) {
	p[++num].next=head[x];
	p[num].to=y;
	head[x]=num;
}
int dfn[N], low[N], tim, cut[N];
// tim 代表入栈的顺序是第几个
// cut[i]代表该点是否是割点

void tag (int x,int zx) {
	// zx 代表最早出现的祖先
	int kid = 0;
	dfn[x] = low[x] = ++tim;
	
	for(int i=head[x]; i; i=p[i].next) {
		int v = p[i].to;
		
		if(!dfn[v]) {
			tag(v, zx);
			low[x] = min(low[v], low[x]);
			if(low[v] >= dfn[x] && x!=zx) cut[x]=1;
			if(x==zx) kid++;
		}
		
		low[x] = min(low[x], dfn[v]);
	}
	if(kid>1 && x==zx) cut[x]=1;
	// 如果有两个及以上的儿子，则也是割点
}

int ans;

int main() {
	fastio;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}
	
	for(int i=1;i<=n;i++) if(!dfn[i]) tag(i,i);
	
	for(int i=1;i<=n;i++) ans += cut[i];
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(cut[i]) printf("%d ",i);
		
	return 0;
}
