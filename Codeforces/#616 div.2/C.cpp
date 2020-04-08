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

int T; int n,m,k; int a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        k = min( k, m-1 );
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        int lft = n - m + 1;
        int ans = 0, cmp = INF; 
        for( int pre=0; pre<=k; pre++ ){
            cmp = INF;
            for( int del=0; del<=m-k-1; del++ ){
                int l = pre + del + 1, r = pre + del + lft;
                cmp = min ( cmp, max( a[l], a[r] ) );
            }
            ans = max( ans,cmp );
        }

        cout<<ans<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/