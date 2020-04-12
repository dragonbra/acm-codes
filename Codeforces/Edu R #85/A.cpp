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

int T,n,m;
int a[N],b[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        
        bool f = true;
        for(int i=1;i<=n;i++){
            if(b[i]-b[i-1] > a[i]-a[i-1] || b[i]<b[i-1] || a[i]<a[i-1] ){
                f = false; break;
            }
        }

        if(f) puts("YES");
        else puts("NO");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/