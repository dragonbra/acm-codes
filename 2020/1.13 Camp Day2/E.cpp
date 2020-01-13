#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 5;

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

int n,f[N]; 
ll cnt = 0, ans[N];

vector<int> G[N];
stack<int> up,low;
set<int> S[N];

void merge(int u,int b){

}

void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        dfs(v);
        merge(1,v);
    }
    ans[u] = cnt; return;
}

int main() {
    redirect();

    scanf("%d",&n); f[1] = 1;
    for(int i=2;i<=n;i++){
        scanf("%d",&f[i]);
        G[f[i]].push_back(i);
    }

    dfs(1);

    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/