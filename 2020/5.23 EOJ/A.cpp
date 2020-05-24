/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-05-23 12:58
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

int n, m; char s[N];

int main() {
    redirect();

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", s);
    }

    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%s", s);
    }

    if (n>m) {
        printf("Cuber QQ\n");
    } else {
        printf("Quber CC\n");
    }

    return 0;
}