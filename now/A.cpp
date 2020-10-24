/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-10-24 12:24
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

ll fac(ll l, ll r) {
    if (l >= r) {
        return l;
    }
    return fac(l, (l+r)/2) * fac((l+r)/2+1, r) % mod;
}

int main() {
    redirect();
    
    int T; cin >> T;
    while (T--) {
        
    }

    return 0;
}