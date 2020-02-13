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

int n,m; int a[N];

int main() {
    redirect();

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[9]) cnt++;
    }

    double idx = (double)a[9] / (double) m;
    if( cnt<=2 || idx>0.8 ) puts("Yes");
    else puts("No");

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/