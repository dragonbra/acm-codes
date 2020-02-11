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

int T,n;

int main() {
    redirect();

    cin>>T;
    ll a[101];
    a[0]=1,a[1]=2;
    for(int i=2;i<=100;i++) a[i] = a[i-1] + a[i-2];
    while(T--){
        cin>>n;
        if(n==0) cout<<1<<endl;
        else cout<<a[n]+a[n-1]<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/