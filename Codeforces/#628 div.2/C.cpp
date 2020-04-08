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

struct node{
    int u,v;
    int idx, label;
} a[N];

int n; int sz[N];

vector<int> G[N];

bool cmp2(node a,node b){
    return a.idx < b.idx;
}

int main() {
    redirect();

    cin>>n;
    for(int i=1;i<=n;i++) a[i].idx = i;
    for(int i=1;i<=n-1;i++) {
        int u,v;
        cin>>u>>v;
        a[i].u = u; a[i].v = v;
        sz[u]++; sz[v]++;
        G[u].push_back(i);
        G[v].push_back(i);
    }

    int res = 0;
    for(int i=1;i<=n;i++) {
        if(sz[i]==1&&a[ G[i][0] ].idx!=0) {
            a[ G[i][0] ].idx = 0;
            a[ G[i][0] ].label = res;
            //cout<<"``"<<G[i][0]<<endl;
            res++;
        }
    }

    for(int i=1;i<=n-1;i++){
        if(a[i].idx!=0) a[i].label = res, res++;
    }

    for(int i=1;i<=n-1;i++){
        printf("%d\n",a[i].label);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/