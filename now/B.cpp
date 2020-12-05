/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-12-01 16:04
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T; ll n;
ll f[N];

int main() {
    redirect();

    scanf("%d",&T);
    for (int i=1; i<=10000; i++) {
        f[i] = f[i-1] + i;
    }
    while (T--) {
        cin >> n;
        int pos = lower_bound(f+1, f+10000+1, n) - f;
        if (f[pos] - n == 1) pos ++;
        int ans = pos;
        cout << ans << endl;
    }

    return 0;
}