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

int n,x,a,b;

int main() {
    redirect();

    scanf("%d%d%d%d",&n,&x,&a,&b);
    double p = (double) x / 100.0 * (double) n, np = (double) n - p;
    double ans = p * (double) a + np * (double) b;
    printf("%.2lf\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/