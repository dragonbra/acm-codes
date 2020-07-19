/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 14:05
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
int n, m;
int x[N], y[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ans = INF;
        for (int i=1; i<=n; i++) {
            cin >> x[i] >> y[i];
            ans = min(ans, ( (m-1)/x[i] + 1 ) * y[i] );
        }
        cout << ans << endl;
    }

    return 0;
}