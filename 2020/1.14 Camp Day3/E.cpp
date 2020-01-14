#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 500 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T,n,m;
char a[N][N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        ll ans = 0;
        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++){
            scanf("%s",a[i]);
            //cout<<a[i]<<endl;
            for(int j=0;j<m;j++){
                if(a[i][j]=='1') ans += j+1;
            }
        }

        if(a[1][0]!='1') puts("aoligei");
        else puts("call");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/