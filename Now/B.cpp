
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); std::cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n, m;
int a[N], b[N];

bool check(int x) {
    int pt = 1;
    for (int i=1; i<=m; i++) {
        if (abs(a[pt] - b[i]) <= x) pt ++;
        if (pt > n) break;
    }
    // cout << x << ' ' << pt << endl;
    if (pt > n) return true;
    return false;
}

int main() {
    redirect();

    cin >> n >> m;
    if (n < m) {
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=m; i++) cin >> b[i];
    } else {
        swap(n, m);
        for (int i=1; i<=m; i++) cin >> b[i];
        for (int i=1; i<=n; i++) cin >> a[i];
    }

    sort (a+1, a+n+1);
    sort (b+1, b+m+1);

    int l = 0, r = 2e9; int mid = 0;
    int ans = 0;
    while (l <= r) {
        mid = (l+r) / 2;
        // check code here
        if (check(mid)) {
            ans = mid; r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << "\n";

    return 0;
}