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

ll fac(ll x){
    ll res = 0;
    ll t = sqrt(x);
    for(int i=1;i<=t;i++){
        if(x%i==0) {
            if(i==t&&t*t==x) res+=1;
            else res+=2;
        }
    }
    //cout<<res<<endl;
    return res;
}

int main() {
    redirect();

    ll n; 
    scanf("%lld",&n);
    int ans = 0;
    while(n!=2){
        n = fac(n); ans++;
    }
    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/