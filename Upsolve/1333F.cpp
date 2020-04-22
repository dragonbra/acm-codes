#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
bool flag[N];
int max_div[N];

void eratosthenes() {
    max_div[1] = 1;
    for(int i=2;i<=n;i++) {
        if ( max_div[i] ) continue;
        for ( int j = i; j <= n; j += i ) {
            if ( max_div[j] ) continue;
            max_div[j] = j / i;
        }
    }
}

int main() {
    redirect();

    scanf("%d",&n);
    eratosthenes();

    sort(max_div+1,max_div+n+1);
    for( int i=2;i<=n;i++ ) printf("%d ",max_div[i]);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/