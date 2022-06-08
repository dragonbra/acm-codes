#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int a[N], suf[N];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i -- ) {
        suf[i] = max(suf[i + 1], a[i + 1]);
    }

    int cnt = 0; int mx = 0;
    for (int i = 1; i <= n; i ++ ) {
        suf[i] = max(suf[i], mx);
        if (suf[i] > a[i]) {
            cnt ++ ;
            mx = suf[i];
        }
    }

    cout << cnt << endl;

    return 0;
}