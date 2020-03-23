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

int n,a[N];

int main() {
    redirect();

    int T = 0;
    while(cin>>n) {
        if(n==0) break;
        T++;
        if(T>1) cout<<endl;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);

        for(int i=1;i<=n/2;i++) {
            cout<<a[i];
            //if(i!=n/2) 
            cout<<' ';
        }
        cout<<endl;
        for(int i=n/2+1;i<=n;i++) {
            cout<<a[i];
            //if(i!=n) 
            cout<<' ';
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/