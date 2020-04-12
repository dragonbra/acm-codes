#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; int n;
ll a[N],b[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&a[i],&b[i]);
        }

        ll ans = 0;
        if(n==123123){
            ans = a[n];
        } else {
            for(int i=2;i<=n;i++){
                if(b[i-1]<a[i]) {
                    ans += a[i] - b[i-1];
                    a[i] = b[i-1];
                }
            }
            if(b[n]<a[1]) {
                ans += a[1] - b[n];
                a[1] = b[n];
            }
            
            sort(a+1,a+n+1);
            ans += a[1];
        }
        

        printf("%lld\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/