#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 21;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,m;
vector<int> G[N];
bool vis[N]; int dep[N]; int ans = INF;
int a[20]; bool vv[N][N];

struct edge{
    int u,v;
} E[N*10];

bool check(){
    for(int i=1;i<=m;i++){
        int u = E[i].u, v = E[i].v;
        if(a[u]==0 && a[v]==0) return false;
    }
    return true;
}

void update(){
    queue<int> Q; memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        if( a[i]==0 ) vis[i] = 1, Q.push(i);
    }
    while( !Q.empty() ) {
        int u = Q.front(); Q.pop();
        for( auto v:G[u] ){
            if( a[v] != 0 ){
                dep[v] = max( dep[v], dep[u] + 1 ),   
                Q.push(v);
            }
            //if( !vis[v] ) vis[v] = 1, Q.push(v);
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) return;
        cnt++;
    }
    if(cnt==n) return;

    int cmp = 0;
    for(int i=1;i<=n;i++){
        cmp = max( cmp, dep[i] );
    }
    if( ans > cmp ){
        for(int i=1;i<=n;i++) cout<<a[i]; cout<<endl;
        ans = cmp;
    }
    return;
}

void dfs(int x){
    if( x==n+1 && check() ){
        update();
        return;
    }

    for(int i=0;i<=1;i++){//=0 no out, =1 has out
        a[x] = i;
        dfs(x+1);
    }
}

int main() {
    redirect();

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        E[i].u = u, E[i].v = v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);

    printf("%d\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/