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
const int N = 4e5 + 10;

void redirect() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T, n, k;
int a[N]; 
int cnt[N]; int pre[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n >> k;

        for (int i=2; i<=2*k; i++) pre[i] = cnt[i] = 0;

        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i*2<=n; i++) {
            cnt[a[i]+a[n-i+1]] ++;
            pre[2] += 2; pre[2*k+1] -= 2;
            int mint = min(a[i], a[n-i+1]), maxt = max(a[i],a[n-i+1]);
            pre[mint+1] += (-2+1); pre[maxt+k+1] += 1;
        }

        //for (int i=2; i<=2*k; i++) cout << cnt[i] << ' '; cout << endl;
        //for (int i=2; i<=2*k; i++) cout << pre[i] << ' '; cout << endl;

        int acc = 0; int ans = INF;
        for (int i=2; i<=2*k; i++) {
            acc += pre[i];
            ans = min(ans, acc-cnt[i]);
        }

        cout << ans << endl;
    }

    return 0;
}