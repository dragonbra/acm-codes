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

int T,n; ll x;
ll a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&x);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);

        ll sum = 0, cmp = 0; int ans = 0;
        for(int i=n;i>=1;i--){
            sum += a[i]; cmp += x;
            ans ++;

            if( sum < cmp ) {
                ans--; break;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/