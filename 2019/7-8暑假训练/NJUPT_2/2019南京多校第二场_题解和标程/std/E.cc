#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
int main() {
    LL q, l, r;
    ios::sync_with_stdio(false);
    cin >> q;
    for (LL cs = 1; cs <= q; ++cs) {
        cin >> l >> r;
        LL x = l + r, y = r - l + 1;
        if (x & 1)  y >>= 1;
        else x >>= 1;
        cout << ((x % 9) * (y % 9) % 9) << endl; 
    }
    return 0;
}