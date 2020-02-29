#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,cnt;
int a[N][N]; int f[N];

struct node{
    int u,v,w;
} E[N*N],ans[N];

int getf(int x){
    return x==f[x] ? x : f[x] = getf(f[x]);
}

bool cmp(node a,node b){
    return a.w < b.w;
}

int main() {
    redirect();

    scanf("%d",&n);

    for(int i=1;i<=n;i++) f[i] = i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(j<i) {
                ++cnt; 
                E[cnt].u = i, E[cnt].v = j, E[cnt].w = a[i][j];
            }
        }
    }

    sort(E+1,E+cnt+1,cmp);

    int mk = 0;
    for(int i=1;i<=cnt;i++){
        node t = E[i];
        int u = t.u, v = t.v; swap(u,v);
        if(getf(u)!=getf(v)){
            f[getf(u)] = getf(v); //cout<<u<<' '<<v<<' '<<getf(u)<<' '<<getf(v)<<" h"<<endl;
            ++mk;
            ans[mk].u = u, ans[mk].v = v;
        }
    }

    for(int i=1;i<=mk;i++){
        printf("%d %d\n",ans[i].u,ans[i].v);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/