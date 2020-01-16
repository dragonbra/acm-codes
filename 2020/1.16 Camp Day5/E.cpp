#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 300 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
ll a[N], b[N], cnt[N][N];

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=4;i++) scanf("%lld",&b[i]);

    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n;j++) cnt[i][j] = cnt[i+1][j];
        cnt[i][ a[i+1] ] ++;
        for(int j=1;j<=n;j++) cnt[i][0] += cnt[i][j];
    }

    ll ans = 0;
    for(int i=1;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
            if( (a[i]==a[j]) != (b[1]==b[2]) ) continue;
            for(int k=j+1;k<=n-1;k++){
                if( (a[i]==a[k]) != (b[1]==b[3]) ) continue;
                if( (a[j]==a[k]) != (b[2]==b[3]) ) continue;

                if( b[4] == b[1] ) ans += cnt[k][ a[i] ];
                else if( b[4] == b[2] ) ans += cnt[k][ a[j] ];
                else if( b[4] == b[3] ) ans += cnt[k][ a[k] ];
                else {
                    ll t = cnt[k][0]; int tt[5]; int c = 0;
                    tt[++c] = a[i]; 
                    if(a[j]!=a[i]) tt[++c] = a[j]; 
                    if(a[k]!=a[i]&&a[k]!=a[j]) tt[++c] = a[k];
                    for(int ii=1;ii<=c;ii++) t -= cnt[k][ tt[ii] ];
                    ans += max( (ll)0, t );
                }
            }
        }
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/