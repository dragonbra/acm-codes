#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T,n;

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        if (n%4) {
            puts("NO");
            continue;
        }
        puts("YES");

        int cmp = n/2+1;
        for (int i=2;i<=(cmp-2)+cmp; i+=2){
            printf("%d ",i);
        }
        for (int i=1;i<=(cmp-1)+cmp; i+=2){
            if(i==cmp) continue;
            printf("%d ",i);
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