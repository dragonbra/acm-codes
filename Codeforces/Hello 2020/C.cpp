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
const int N = 3e5 + 5;

//#define LOCAL
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

ll n,m;
ll f[N];

int main() {
    redirect();
    scanf("%lld%lld",&n,&m);

    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i] = f[i-1]*i; f[i]%=m;
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += (f[i] * (f[n-i+1]*(n-i+1)%m) ) % m; ans %= m;
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/