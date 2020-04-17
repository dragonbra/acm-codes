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

int T, n;
int a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int mid = (1+n)/2;
        int cnt = 0; bool f = 0;
        while(cnt<n){
            cnt++;
            int pos = 0;
            if(cnt%2) pos = mid - cnt/2;
            else pos = mid + cnt/2;
            printf("%d ",a[pos]);

            if(cnt==n) break;
        }
        printf("\n");
        
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/