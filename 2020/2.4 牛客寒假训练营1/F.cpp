#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n; char s[N]; ll ans = 0;
int f[N]; int sz[N]; bool vis[N];
vector<int> G[N];

int getf(int x){
    return f[x]==x? x:f[x]=getf(f[x]);
}

void dfs(int u){
    for(auto v:G[u]){
        if(s[v]=='W'&&!vis[v]) {
            f[v] = getf(u); sz[f[v]] ++;
            vis[v] = 1; dfs(v);
        }
    }
}

int main() {
    redirect();

    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        f[i]=i;
        if(s[i]=='W') sz[i]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }

    for(int u=1;u<=n;u++){
        if(s[u]=='B'){
            for(auto v:G[u]){
                if(s[v]=='B') continue;

                if(vis[v]) sz[u] += sz[getf(v)];
                else vis[v] = 1, dfs(v), sz[u] += sz[getf(v)];
            }

            ans += sz[u];

            ll res = 0;
            for(auto v:G[u]){
                if(s[v]=='B') continue;
                res += sz[getf(v)] * (sz[u] - sz[getf(v)]);
            }

            ans += (res/2);
        }
    }
    //for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<endl;
    //for(int i=1;i<=n;i++) cout<<sz[i]<<' ';cout<<endl;

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/