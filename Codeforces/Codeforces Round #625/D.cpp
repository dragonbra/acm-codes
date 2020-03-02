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

vector<int> G[N];
int n,m,k;
int d[N]; bool vis[N];

struct node{
    int d,cnt;
    int x;
    bool operator < (const node &a) const{
        return d > a.d;
    }
} a[N];

int main() {
    redirect();

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[v].push_back(u);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&d[i]);
    }

    node t; t.x = d[k], t.d = 0;
    priority_queue<node> Q; Q.push(t); vis[d[k]] = 1;
    while(!Q.empty()){
        node x = Q.top(); Q.pop();
        int u = x.x; int dis = x.d;
        //cout<<u<<endl;
        for(auto v:G[u]){
            if( !vis[v] ){
                vis[v] = true;
                a[v].d = dis+1, a[v].cnt = 1;
                node tt; tt.d = dis+1; tt.x = v;
                Q.push(tt);
            } else if(dis+1==a[v].d){
                a[v].cnt++;
            }
        }

    }

    //for(int i=1;i<=n;i++) cout<<i<<' '<<a[i].d<<' '<<a[i].cnt<<endl;

    int ans1=0, ans2=0;
    for(int i=1;i<k;i++){
        if(a[d[i]].d<(k-i)) ans1++,ans2++;
        else if(a[d[i]].cnt>1) ans2++;
    }

    cout<<ans1<<' '<<ans2<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/