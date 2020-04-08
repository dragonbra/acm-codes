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

int T; int n;
int a[N], b[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);

        bool f = true;
        bool fless = false, fgreat = false;
        for(int i=1;i<=n;i++){
            if(a[i]==b[i]){

            } else if(a[i]<b[i]){
                if(!fgreat) {
                    f = false; break;
                }
            } else if(a[i]>b[i]){
                if(!fless) {
                    f = false; break;
                }
            }

            if(a[i]==1) fgreat = true;
            if(a[i]==-1) fless = true;
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