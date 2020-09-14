/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-14 22:36
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

int T;
ll x, y, k;

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> x >> y >> k;
        ll ans = ((y*k + k - 1 + (x-2)) / (x-1)) + k;
        cout << ans << endl;
    }

    return 0;
}