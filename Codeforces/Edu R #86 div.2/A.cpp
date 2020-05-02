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

int T;
ll a,b,x,y;

int main() {
    redirect();

    //ios::sync_with_stdio(false);
    //cin.tie(0);

    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&x,&y);
        scanf("%lld%lld",&a,&b);
        if (a*2<b) b = 2*a;

        ll ans = ( max(x,y) - min(x,y) ) * a + min(x,y) * b;

        printf("%lld\n",ans); 
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/