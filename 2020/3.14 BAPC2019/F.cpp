#include <bits/stdc++.h>

using namespace std;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int main() {
    redirect();

    long long n; cin >> n;
    
    if(n % 2 == 1) {
        printf("%lld %lld\n", (n+1)/2, (n-1)/2);
    }
    else if(n % 4 == 0) {
        printf("%lld %lld\n", n/4 + 1, n/4 - 1);
    }
    else {
        printf("impossible\n");
    }
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/