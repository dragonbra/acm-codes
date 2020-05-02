#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 4e4 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; 
ll a, b; int q;
ll l, r;
int pre[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> a >> b >> q;

        ll cmp = a*b; pre[0] = 0; 

        for (int i=1; i<=cmp; i++) {
            pre[i] = pre[i-1];
            if ((i%a%b)!=(i%b%a)) pre[i]++;
            //cout << i << ' ' << pre[i] << endl;
        }

        for (int i=1; i<=q; i++) {
            cin >> l >> r;
            ll ansr = pre[cmp] * (r/cmp) + pre[r%cmp];
            ll ansl = pre[cmp] * ( (l-1)/cmp ) + pre[(l-1)%cmp];

            //cout << endl << ansl << ' ' << ansr << endl;

            ll ans = ansr - ansl;
            cout << ans << ' ';
        }

        cout << endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/