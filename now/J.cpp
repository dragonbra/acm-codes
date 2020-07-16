/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-16 00:08
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

ll n, k;
int a[N]; int ans[N];
bool vis[N];

int main() {
    redirect();

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for (int i=1; i<=n; i++) {
        vector<int> Perm;
        if (!vis[i]) {
            int x = i;
            while (!vis[x]) {
                vis[x] = true;
                Perm.push_back(x);
                x = a[x];
            }
            int inv;
            for (int j=0; j<Perm.size(); j++) {
                if (1ll * k * j % Perm.size() == 1) inv = j;
            }
            for (int j=0; j<Perm.size(); j++) {
                ans[Perm[j]] = Perm[(j+inv)%Perm.size()];
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}