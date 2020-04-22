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

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        int res = 1; int x = 2;
        for (int i=1;i<=31;i++) {
            res += x; x *= 2;
            if (n%res==0) {
                cout << n / res << endl;
                break;
            }
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/