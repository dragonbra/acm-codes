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

int n, m;
int pre[N]; int cnt[N];
ll ans = 0;

int main() {
    redirect();

    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        pre[l]++; pre[r+1]--;
    }

    int acc = 0;
    for (int i=1; i<=n; i++) {
        acc += pre[i];
        cnt[i] = acc;
    }

    sort(cnt+1, cnt+n+1);

    for (int i=n; i>=1; i--) {
        ll res = 1ll * cnt[i] * i;
        ans += res;
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/