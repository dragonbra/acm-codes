#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5+10;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

struct node{
	int pos,f;
	node(int pos,int f):pos(pos),f(f){};
};

queue<int> Q;

vector<int> G[N];

int n,m,s1,s2;
int vis[3][N],f[N];

int main() {
	redirect();
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&s1,&s2);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=m;i++){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		memset(vis,0,sizeof vis);
		
		Q.push(s2); vis[1][s2]=1; f[s2]=-1;
		while(!Q.empty()){
			int t = Q.front(); Q.pop();
			
			for(int i=0;i<G[t].size();i++){
				if( vis[1][ G[t][i] ] == 0 && G[t][i] != s1 ) Q.push( G[t][i] ), vis[1][ G[t][i] ] = 1, f[ G[t][i] ] = t;
			}
		}
		
		Q.push(s1); vis[2][s1]=1; f[s1]=-1;
		while(!Q.empty()){
			int t = Q.front(); Q.pop();
			for(int i=0;i<G[t].size();i++){
				if( vis[2][ G[t][i] ] == 0 && G[t][i] != s2 ) Q.push( G[t][i] ), vis[2][ G[t][i] ] = 1, f[ G[t][i] ] = t;
			}
		}
		
		ll c1 = 0, c2 = 0, c3 = 0;
		for(int i=1;i<=n;i++){
			if(vis[1][i] == 0 && vis[2][i] == 1 && i!=s1) c1++;
			if(vis[1][i] == 1 && vis[2][i] == 0 && i!=s2) c3++;
		}
		c2 = n - 2 - c1 - c3;
		
		ll ans = c1*c3;
		printf("%lld%c",ans,T==0?' ':'\n');
	}
}

/*
-----------------
author:dragon_bra
-----------------
*/
