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
ll sons[N];
bool vis[N]; ll ans = 0;
vector<int> G[N];

struct node{
    ll depth, sons, increase;
} a[N];

bool cmp(node a, node b){
    return a.increase > b.increase;
}

void dfs(int u, ll depth) {
    for( auto v:G[u] ) {
        if( !vis[v] ) {
            vis[v] = true;
            dfs(v,depth+1);
            sons[u] += (sons[v]+1);
        }
    }
    a[++cnt].depth = depth, a[cnt].sons = sons[u];
    a[cnt].increase = a[cnt].depth - 1 - a[cnt].sons;
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
        //printf("%d %d\n",a[i].depth,a[i].sons);
        ans += a[i].increase;
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/