#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int maxn = 3e5+10;
int n,m,a[maxn],sum[maxn];
bool C(int k){
    int res = 0;
    int pos = upper_bound(a+1,a+n+1,k) - a;
    if(pos != 0) res = sum[pos-1] + (n-pos+1) * k;
    else res = n * k;
    return k * m <= res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t-->0) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        sum[1] = a[1];
        for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + a[i];
        int l = 0, r = sum[n] + 10;
        int ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (C(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
