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

ll n,m;
ll a[N];
ll ans[N], sum = 0;

int main() {
    redirect();

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%lld",&a[i]); sum+=a[i];
    }

    ll res = 0;
    for(int i=m;i>=1;i--){
        if(a[i]>res+1){
            res = a[i];
            ans[i] = 1;
        } else {
            res = res + 1;
            ans[i] = res + 1 - a[i];
        }
    }

    if( res > n || sum < n) puts("-1");
    else {
        res = n;
        for(int i=1;i<=m;i++){
            if(res<=ans[i]+a[i]-1) break;
            ans[i] = res + 1 - a[i];
            res = ans[i] - 1;
        }
        for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/