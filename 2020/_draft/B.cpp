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

ll k,ans[N]; int cnt;

int main() {
    redirect();

    cin>>k;

    ll cmp = -sqrt(k);
    for(ll i=cmp;i<=-1;i++){
        ll temp = -i*i + k; if(temp<=0) continue;
        if( (ll)sqrt(temp) * (ll)sqrt(temp) == temp ) ans[++cnt] = -i*i ;
    }

    //cout<<cnt<<endl;

    for(ll i=1;i*i<k;i++){
        if(k%i==0){
            ll x = i, y = k/x ;
            ll a = (y-x)/2, b = (x+y)/2;
            if(a==0||b==0||k!=(b-a)*(b+a)) continue;
            ans[++cnt] = a*a;
            ans[++cnt] = -b*b;
        }
    }

    sort(ans+1,ans+cnt+1);

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<ans[i]<<' ';

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/