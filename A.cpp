/*
* @ author: dragon_bra
* @ date: 2021-05-29 21:17
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n;
string s;
vector<int> pos1, pos2;

void init() {
    pos1.clear(); pos2.clear();
    queue<int> s1, s2;

    for (int i = 0; i < n; i ++ ) {
        if (s[i] == '2') {
            s1.push(i);
        }
        if (s[i] == '0' && s1.size()) {
            pos1.push_back( i );
            s1.pop();
        }
    }

    for (int i = n - 1; i >= 0; i -- ) {
        if (s[i] == '0') {
            s2.push(i);
        }
        if (s[i] == '2' && s2.size()) {
            pos2.push_back( i );
            s2.pop();
        }
    }

    // cout << "--------" << endl;
    // for (int x : pos1) cout << x << ' '; cout << endl;
    // for (int x : pos2) cout << x << ' '; cout << endl;
    // cout << "--------" << endl;
}

bool check (int num) {
    if (pos1.size() < num * 2 || pos2.size() < num * 2) return false;

    for (int i = 0; i < num; i ++ ) {
        if (pos1[i] > pos2[num - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    while (cin >> n) {
        cin >> s;

        init();

        int l = 0, r = n; int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ( check(mid) ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}