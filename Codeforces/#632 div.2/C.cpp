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

int n;
ll a[N], b[N];
ll lft = N, rt = 0;
ll ans = 0;
map<ll,ll> mp;

int main() {
    redirect();

    scanf("%d",&n);

    //ans = (n+1) * n / 2;
    mp[0] = 1; ll cnt = 0;

    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i] = b[i-1] + a[i];
        cnt++;
        if(mp[b[i]]==0){
            mp[b[i]] = i+1;
        } else {
            rt = max(rt,mp[b[i]]);
            mp[b[i]] = i+1;
        }
        cout<<i<<' '<<ans<<' '<<cnt<<' '<<rt<<endl;
        ans += (cnt-rt);
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/