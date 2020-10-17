/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-25 14:48
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
const int N = 3e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n;
string a, b;

string permu[7] = {"", " abc", " acb", " bac", " bca", " cab", " cba"};

vector<string> all[7]; // 1-abc, 2-acb, 3-bac, 4-bca, 5-cab, 6-cba
vector<string> per[7];
string ls1[4] = {"", "aa", "bb", "cc"};
string ls2[7][4] = { {},
                    {"", "ab", "bc", "ca"},
                    {"", "ac", "cb", "ba"},
                    {"", "ba", "ac", "cb"},
                    {"", "bc", "ca", "ab"},
                    {"", "ca", "ab", "bc"},
                    {"", "cb", "ba", "ac"}};

char s[N];

int main() {
    redirect();

    cin >> n >> a >> b;
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=3; j++) {
            all[i].push_back(ls1[j]);
            if (j!=3) all[i].push_back(ls2[i][j]);
            if (n==1 && j==3) continue;
            per[i].push_back(ls2[i][j]);
        }
    }

    bool flag = false; int cnt = 0;
    if (n>1) {
        for (int i=1; i<=6; i++) {
            flag = true;
            for (auto str:all[i]) {
                if (a == str || b == str) {
                    flag = false; break;
                }
            }
            if (flag) { cnt = i; break; }
        }
    }

    if (flag) {
        int pos = 0;
        for (int i=1; i<=3; i++) {
            for (int j=1; j<=n; j++) {
                s[++pos] = permu[cnt][i];
            }
        }
        printf("YES\n%s\n", s+1);
    } else {
        for (int i=1; i<=6; i++) {
            flag = true;
            for (auto str:per[i]) {
                if (a == str || b == str) {
                    flag = false; break;
                }
            }
            if (flag) { cnt = i; break; }
        } if (flag) {
            int pos = 0;
            for (int j=1; j<=n; j++) {
                for (int i=1; i<=3; i++) {
                    s[++pos] = permu[cnt][i];
                }
            }
            printf("YES\n%s\n", s+1);
        } else {
            printf("NO\n");
        }
    }

    

    return 0;
}