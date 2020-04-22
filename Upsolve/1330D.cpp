/*
    CF R #631 B
*/
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

int T;
int d,m;

int f[N];
ll c[N]; ll ans;

int main() {
    redirect();

    f[0] = 1;
    for( int i=1; i<=30 ; i++ ){
        f[i] = f[i-1]<<1;
    }

    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&d,&m);

        int cnt = 0;
        while( f[cnt+1] <= d ) cnt++;
        ans = 1;
        for ( int i=0; i<=cnt; i++) {
            c[i] = min(f[i+1]-1,d) - f[i] + 2;
            ans *= c[i]; ans %= m;
        }
        ans += m; ans -= 1; ans %= m;

        printf("%lld\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/