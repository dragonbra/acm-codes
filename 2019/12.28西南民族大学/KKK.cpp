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
const int N = 5e3 + 5;

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

int n,s,m;

int f[N]; vector<int> G[N];
int vis[N]; //1-vised, 2-loop
int c[N],b[N];

int w[N]; ll v[N];
ll dp[N][N];

void make_tree(int x){
    //cout<<x<<' '<<G[x].size()<<endl;
    int size = G[x].size();
    if(size==0) return;
    for(int i=0;i<size;i++){
        if(i==0){
            c[x] = G[x][i];
        } else {
            b[ G[x][i-1] ] = G[x][i];
        }
        make_tree( G[x][i] );
    }
}

ll dfs(int x,int k)
{
    if(dp[x][k]>0)    return(dp[x][k]);
    if(x==0 || k<=0)    return(0);
    //不取x
    dp[b[x]][k] = dfs(b[x],k);
    dp[x][k] = dp[b[x]][k];

    int y=k-w[x];
    for(int i=0;i<=y;i++){
        dp[c[x]][y-i] = dfs(c[x],y-i);
        dp[b[x]][i] = dfs(b[x],i);
        dp[x][k] = max( dp[x][k] , v[x]+dp[c[x]][y-i]+dp[b[x]][i] );
    }

    return(dp[x][k]);
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int x : G[u]) {
        for (int i = 0; i <= s; i++) {
            if (i >= w[x]) dp[x][i] = dp[u][i - w[x]] + v[x];
            else dp[x][i] = -1e18;
        }
        dfs(x);
        for (int i = 0; i <= s; i++) dp[u][i] = max(dp[u][i],dp[x][i]);
    }
}

int main() {
    redirect();

    scanf("%d%d%d",&n,&s,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[v].push_back(u); f[u] = v;
    }

    for(int i=1;i<=n;i++){
        if(f[i]==0) G[0].push_back(i);
    }

    make_tree(0);
    
    //for(int i=1;i<=n;i++) cout<<c[i]<<' '; cout<<endl;

    ll ans = dfs(c[0],s);
    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/