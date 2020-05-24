/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-05-23 13:28
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

int n, k;

int main() {
    redirect();

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        if (i==1) cout << "b";
        else if (i<=k) cout << "a";
        else cout << "c";
    }
    cout << endl;

    return 0;
}