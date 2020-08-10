/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-08-10 12:36
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

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

int T, n;
int b[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        int mx = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &b[i]);
            mx = max(mx, b[i]);
        }

        int l = 0, r = mx;
        while (l < r) {
            int mid = (l+r) / 2;
            ll res = 0;
            for (int i=n; i>=1; i--) {
                if (b[i] > mid) {
                    res += (b[i]-mid);
                } else if (b[i] < mid && res > 0) {
                    res -= (mid-b[i]);
                    if (res < 0) res = 0;
                }
            }
            //cout << mid << ' ' << res << endl;
            if (res == 0) r = mid;
            else l = mid + 1;
        }

        printf("%d\n", l);
    }

    return 0;
}