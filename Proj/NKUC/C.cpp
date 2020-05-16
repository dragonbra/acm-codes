#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
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
int a[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        ll ans = 0; bool f;
        for (int i=1; i<=n; ) {
            if (a[i]>0) f = 1;
            else f = 0;

            int res = a[i];
            ans += res;
            int j = i+1;
            
            if (f) {
                while (j<=n && a[j]>0) {
                    res = max(res, a[j]);
                    j++;
                }
                ans -= a[i];
                ans += res;
            } else {
                while (j<=n && a[j]<0) {
                    res = max(res, a[j]);
                    j++;
                }
                ans -= a[i];
                ans += res;
            }

            i = j;

            // cout << res << ' ';
        }
        
        cout << ans << endl;

    }

    return 0;
}