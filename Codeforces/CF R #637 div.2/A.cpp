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

int T, n;
int a, b, c, d;

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n >> a >> b >> c >> d;

        bool f = true;
        int sum1 = (a-b)*n, sum2 = (a+b)*n;

        if (sum2<c-d || sum1>c+d) f = false;

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