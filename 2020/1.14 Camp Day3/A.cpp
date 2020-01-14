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

int n;
ll a[N][N], pre[N];
ll sum, a1;

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }

    a1 = (a[1][2] + a[1][3] - a[2][3] ) / 2;

    for(int i=1;i<=n;i++){
        if(i==1) cout<<a1;
        else cout<<a[1][i] - a1;
        if(i!=n) cout<<' ';
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/