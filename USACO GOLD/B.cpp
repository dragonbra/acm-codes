#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    freopen("fcolor.in","r",stdin);
    freopen("fcolor.out","w",stdout);
}

int n,m;
vector<int> to[N],from[N];
queue<int> Q;
int num[N];bool vis[N];
map<int,int> idx;bool f[N*3];

int main() {
    redirect();

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        to[u].push_back(v);
        from[v].push_back(u);
    }

    num[1] = 1; int type = 0;
    Q.push(1);
    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        for(auto v:to[x]){
            if(!vis[v]) {
                vis[v] = true;
                num[v] = num[x] + 1;

                type = max(type, num[v]);

                Q.push(v);
                //cout<<"v: "<<v<<' '<<num[v]<<endl;
            }
        }
        for(auto u:from[x]){
            if(!vis[u]){
                vis[u] = true;
                num[u] = num[x] - 1;
                Q.push(u);
                //cout<<"u: "<<u<<' '<<num[u]<<endl;
            }
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(num[i]<1) num[i]+=type;
        if( !f[ num[i] ]){
            f[ num[i] ] = true;
            idx[num[i]] = ++cnt;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<idx[num[i]]<<endl;
    }

    return 0;
}
