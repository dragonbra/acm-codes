/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-05-27 18:16
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n = 1e5;

int main() {
    redirect();

    cout << n << endl;
    for (int i = 1; i <= n; i ++ ) cout << i << ' ' << i << endl;

    return 0;
}