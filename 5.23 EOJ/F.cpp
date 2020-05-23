/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-05-23 13:56
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

int n; 
map<string, int> file;
map<string, int> eojvis;
queue<string> Q;

int main() {
    redirect();

    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        
        // cout << s << endl;

        int len = s.length();
        for (int j=len-1; j>=0; j--) {
            if (j>=3 && s.substr(j-3)==".eoj") {
                if (eojvis[s] == 0) {
                    eojvis[s] = 1;
                    Q.push(s);
                }
            }
            while (s[j]!='/') {
                s.pop_back();
                j--;
            }
            s.pop_back();
            file[s] = 1;
        }
    }
    int ans = 0;
    while (!Q.empty()) {
        string t = Q.front(); Q.pop();
        if (file[t]==0) ans++;
    }

    cout << ans << endl;

    return 0;
}