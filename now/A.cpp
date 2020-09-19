/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-19 22:39
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
string s;

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        cin >> n;
        cin >> s;
        bool odd = false, even = false;
        for (int i=0; i<n; i++) {
            if (i%2==1 && (s[i]-'0')%2==0) {
                even = true;
            } 
            if (i%2==0 && (s[i]-'0')%2==1) {
                odd = true;
            }
        }

        if (n%2==0) {
            if (even == true) puts("2");
            else puts("1");
        } else {
            if (odd == true) puts("1");
            else puts("2");
        }
    }

    return 0;
}