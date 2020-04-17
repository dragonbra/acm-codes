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

int n;
vector<int> G[N];
int in[N]; bool vis[N];
bool dis[N];
int ans = 0 ; bool f = 0;

void dfs(int u,int dst){
    if(in[u]==1) {
        if(dst%2) f = 1;
    }

    for(auto v:G[u]){
        if(!vis[v]){
            vis[v] = 1;
            dfs(v,dst+1);
        }
    }
}

void dfs1(int u,int dst){
    if(dst==2) {
        if(in[u]==1) vis[u] = 1, ans--;
        return;
    }

    for(auto v:G[u]){
        if(!vis[v]){
            //vis[v] = 1;
            dfs1(v,dst+1);
        }
    }    
}

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int u,v; scanf("%d%d",&u,&v);

        G[u].push_back(v);
        G[v].push_back(u);
        in[u]++; in[v]++;
    }

    int s = 0; ans = n-1; dis[2] = 1;
    for(int i=1;i<=n;i++){
        if(in[i]==1) {
            if(s==0) s=i;
            if(!vis[i]) {
                vis[i] = 1;
                dfs1(i,0);
                vis[i] = 0;
            }
        }
    }

    //cout<<s<<endl;
    //for(int i=1;i<=n;i++) cout<<vis[i]<<' '; cout<<endl;
    vis[s] = 1; dfs(s,0);

    if(f) printf("3 ");
    else printf("1 ");
    printf("%d\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/