/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 17:02
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
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n; 
char s[N];
char dest[N] = "abacaba";
char ans[N];
bool vis[N];

bool check(int x) {
    for (int i=0; i<strlen(dest); i++) {
        if (dest[i]!=ans[i+x]) return false;
    }
    return true;
}

bool check2(int x) {
    for (int i=0; i<strlen(dest); i++) {
        if (dest[i]!=s[i+x] && s[i+x]!='?') return false;
    }
    return true;
}

void make(int x) {
    for (int i=0; i<strlen(dest); i++) {
        ans[i+x] = dest[i];
    }
}

bool lstcheck(int x) {
    for (int i=0; i<strlen(s); i++) {
        if (s[i]=='?') ans[i] = 'z';
        else ans[i] = s[i];
    }
    ans[strlen(s)] = '\0';
    if(x>=0) make(x);
    //cout << x << ' ' << ans << endl;

    int cnt = 0;
    for (int i=0; i<strlen(s)-6; i++) {
        if (check(i)) {
            cnt ++;
        }
    }
    if (cnt==1) return true;
    return false;
}

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        //cout << n << endl;
        //cout << s << endl;

        bool f = false;
        if (lstcheck(-1)) f = true;
        for (int i=0; i<strlen(s)-6; i++) {
            if (f) break;
            if (check2(i)) {
                if (lstcheck(i)) {
                    f = true; break;
                }
            }
        }

        if (f) {
            puts("Yes");
            printf("%s\n", ans);
        } else {
            puts("No");
        }
    }

    return 0;
}