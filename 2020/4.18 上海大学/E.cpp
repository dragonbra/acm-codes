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

int n;
ll a[N],ans=-1e14;
ll pre[N];

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];

    ans = pre[n];
    ans -= (1ll * (n-1) * n /2);

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/