#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
int a[N];

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    ll ans = 0;ll pos = 0, mk = 0; ll sum = 0;
    for(int i=2;i<=n;i++){
        ll cmp = a[i-1] * a[i];
        if(cmp>mk) mk = cmp, pos = i;
    }
    ans += mk; int l = pos-1 -1, r = pos +1;
    
    int cnt = n-2;
    while(cnt>0){
        if(l<1) ans += (a[r]*mk), r++;
        else if(r>n) ans += (a[l]*cnt), l--;
        else {
            if(a[l]>a[r]) ans += (a[l]*cnt), l--;
            else ans += (a[r]*cnt), r++;
        }
        cnt--;
    }

    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/