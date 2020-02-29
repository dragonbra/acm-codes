#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e6 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll n,k;
ll a[N]; ll ans=0;

struct node{
    ll val, rk;
} b[N];

bool cmp(node a,node b){
    return a.val<b.val;
}

int main() {
    redirect();

    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+n+1);
    
    for(int i=1;i<=n;i++){
        b[i].val = a[i] - 1ll*i*k, b[i].rk = a[i];
    }

    sort(b+1,b+n+1,cmp);

    ll mid, pos;
    for(int i=1;i<=n;i++){
        if(a[i]==b[n/2+1].rk){
            pos=i; break;
        }
    }
    mid = a[pos];

    for(int i=pos-1;i>=1;i--){
        mid -= k;
        ans += abs(mid-a[i]);
    }

    mid = a[pos];

    for(int i=pos+1;i<=n;i++){
        mid += k;
        ans += abs(mid-a[i]);
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/