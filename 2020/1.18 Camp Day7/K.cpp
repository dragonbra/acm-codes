#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll n,a1,a2;
ll b1[N],b2[N]; ll ans = INF;

void check(ll t1, ll t2){
    ll l = 1, r = 1e6; ll mid;
    while(l<r){
        mid = (l+r)/2; ll cmp = (mid+1)*mid/2;
        if( (mid * a1 + cmp >= t1) && (mid * a2 + cmp >= t2) && (mid * ( a1 + a2 ) + cmp >= ( t1 + t2 )) ) 
            r = mid;
        else l = mid + 1;
    }
    //cout<<l<<endl;
    ans = min(ans, l);
}

int main() {
    redirect();

    scanf("%lld%lld%lld",&a1,&a2,&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&b1[i],&b2[i]);
        check(b1[i],b2[i]);
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/