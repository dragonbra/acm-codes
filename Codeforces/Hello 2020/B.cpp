#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
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

ll n; int cnt; ll ast;
struct node{
    int t;
    bool flag;
} a[N]; int h[N];
int at[N];

bool cmp(node a,node b){
    return a.t<b.t;
}

int main() {
    redirect();
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int t; scanf("%d",&t);
        bool flag = false; int mi = INF, mk = 0;
        for(int j=1;j<=t;j++){
            scanf("%d",&at[j]); mi = min(mi,at[j]); mk = max(mk,at[j]);
            if(j>=2 && at[j]>at[j-1]) flag = true;
        }
        if(flag) ast++;
        else a[++cnt].t = mi, h[cnt] = mk; 
    }

    sort(h+1,h+cnt+1);
    sort(a+1,a+cnt+1,cmp);

    ll ans = 0; int pt = 1;
    ans += (n*n - (n-ast)*(n-ast));
    for(int i=1;i<=cnt;i++){
        while( pt<=cnt && h[pt]<=a[i].t ) pt++;

        if(pt<=cnt) ans += (cnt-pt+1);
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/