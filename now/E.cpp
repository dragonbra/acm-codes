/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-19 23:59
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
vector<int> prime, factor;
map<int, bool> key;
int a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        prime.clear(); factor.clear(); key.clear();

        cin >> n;
    
        factor.push_back(n);
        int pri = n;
        for (int i=2; i*i <= n; i++) {
            if (pri % i == 0) {
                prime.push_back(i);
                while (pri%i==0) pri/=i;
            } 
            if (n%i == 0) {
                if (n==i*i) factor.push_back(i);
                else {
                    factor.push_back(i);
                    factor.push_back(n/i);
                }
            }
        }
        if (pri > 1) prime.push_back(pri);

        int num = prime.size();
        
        key[prime[0] * prime[num-1]] = true;
        for (int i=0; i<num-1; i++) {
            key[prime[i] * prime[i+1]] = true;
        }

        int pos = 0;
        if (num != 2) a[++pos] = prime[0] * prime[num-1];
        for (int i=0; i<num; i++) {
            int p = prime[i];
            for (auto now:factor) {
                // cout << "H" << now << ' ' << key[now] << endl;
                if (now%p == 0 && key[now] == false) {
                    a[++pos] = now;
                    key[now] = true;
                }
            }
            if (i<num-1) a[++pos] = prime[i] * prime[i+1];
        }

        for (int i=1; i<=pos; i++) {
            printf("%d ", a[i]);
        } printf("\n");

        if (num >= 2 && n == prime[0] * prime[1]) puts("1");
        else puts("0");

        // for (auto p:prime) cout << p << ' '; cout << endl;
        // for (auto f:factor) cout << f << ' '; cout << endl;
    }

    return 0;
}