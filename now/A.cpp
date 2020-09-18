/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-17 22:29
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
const int N = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n;
int a[N], bucket[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        for (int i=100; i>=0; i--) bucket[i] = 0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            bucket[a[i]] ++;
        }

        int ans = 0;
        bool flag = false;
        for (int i=0; i<=101; i++) {
            // cout << i << ' ' << bucket[i] << endl;
            if (!flag && bucket[i] < 2) {
                ans += i; flag = true;
            }
            if (flag) {
                if (bucket[i] == 0) {
                    ans += i;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}