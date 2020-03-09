#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; int n,a[N];

int main() {
    redirect();

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int cst = a[1]-1;

        for(int i=n;i>=1;i--) cout<<a[i]<<' '; cout<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/