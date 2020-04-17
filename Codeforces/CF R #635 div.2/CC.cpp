#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,k; int cnt = 0;
bool vis[N]; ll ans = 0;
vector<int> G[N];

struct node{
    int depth, sons;
} a[N];

bool cmp(node a, node b){
    if(a.depth==b.depth) return a.sons < b.sons;
    return a.depth > b.depth;
}

void dfs(int u, int depth) {
    int sons = 0;
    for( auto v:G[u] ) {
        if( !vis[v] ) {
            sons ++;
            vis[v] = true;
            dfs(v,depth+1);
        }
    }
    a[++cnt].depth = depth, a[cnt].sons = sons;
}

int main() {
    redirect();

    scanf("%d%d",&n,&k);

    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vis[1] = true;
    dfs(1,1);

    sort(a+1,a+cnt+1,cmp);

    for(int i=1;i<=k;i++){
        ans += a[i].depth - 1;
        ans -= a[i].sons;
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/