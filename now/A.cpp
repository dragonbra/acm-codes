#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

int n;
priority_queue<int> MX;
priority_queue <int,vector<int>,greater<int> > MI;

int main() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    cin >> n;
    for (int i=1; i<=n; i++) {
        int t; cin >> t;
        if (t > 0) MX.push(t);
        else if (t < 0) MI.push(t);
    }

    int cnt = 0;
    while (MI.size()) {
        int mi = MI.top(); MI.pop();
        int mx = MX.top(); MX.pop();
        cout << mi << ' ' << mx << "\n";
        cnt ++;

        if (abs(mx) >= abs(mi)) {
            mi += mx;
            mx = 0;
            if (mi > 0) MX.push(mi);
            else if (mi < 0) MI.push(mi);
        } else {
            mx += mi;
            mi = 0;
            if (mx > 0) MX.push(mx);
            else if (mx < 0) MI.push(mx);
        }
    }

    cout << cnt << "\n";

    return 0;
}