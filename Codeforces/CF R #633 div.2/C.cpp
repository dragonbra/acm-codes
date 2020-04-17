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

int T, n;
ll a[N]; ll p[110];

int hibit(ll x){
    int res = 0;
    while(x){
        x/=2; res++;
    }
    return res;
}

int main() {
    redirect();

    p[0] = 1;
    for(int i=1;i<=64;i++) p[i] = p[i-1] * 2;
    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

        int ans = 0, pt = 0;
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]){
                ans = max ( ans, hibit(a[i-1]-a[i]));
                a[i] = a[i-1];
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