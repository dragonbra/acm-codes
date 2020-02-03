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

int T; int n; int a[N]; int t[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        bool f1 = true, f2 = true;

        int mid = n/2; t[1] = 0;
        for(int i=2;i<=mid+1;i++){
            t[i] = t[i-1] + 1;
        }
        for(int i=mid+2;i<=n;i++){
            t[i] = t[i-1] - 1;
        }

        for(int i=1;i<=n;i++){
            if(a[i]<t[i]){
                f1 = false; break;
            }
        }

        for(int i=1;i<=n;i++) cout<<t[i]<<' '; cout<<endl;

        if(n%2==0)
            for(int i=1;i<=mid;i++) swap(t[i],t[n+1-i]);

        for(int i=1;i<=n;i++) cout<<t[i]<<' '; cout<<endl;

        for(int i=1;i<=n;i++){
            if(a[i]<t[i]){
                f2 = false; break;
            }
        }

        if(f1||f2) puts("Yes");
        else puts("No");

    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/