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

int T; ll x, n, m;

int main() {
    redirect();

    scanf("%d",&T);
    while(T--) {
        scanf("%lld%lld%lld",&x,&n,&m);

        int t = x;
        for(int i=1;i<=n;i++){
            if(x<=20) break;
            x = x/2 + 10;
        }
        for(int i=1;i<=m;i++){
            x -= 10;
        }
        if(x>0) puts("NO");
        else puts("YES");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/