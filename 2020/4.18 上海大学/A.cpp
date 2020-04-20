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

int a[5];

int main() {
    redirect();

    for(int i=1;i<=4;i++) scanf("%d",&a[i]);
    sort(a+1,a+4+1);

    printf("%d\n",abs(a[1]+a[4] - a[2] - a[3]) );


    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/