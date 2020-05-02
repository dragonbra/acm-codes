#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T;
char t[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> t;
        bool f = 0;
        for (int i=0; i+1<strlen(t); i++) {
            if (t[i]!=t[i+1]) {
                f = 1; break;
            }
        }
        if (!f) cout << t << endl;
        else {
            for (int i=0; i<strlen(t); i++) {
                if (t[i]=='1' && t[i-1]!='0') cout << '0';
                if (t[i]=='0' && t[i-1]!='1') cout << '1';
                cout << t[i];
            }
            cout << endl;
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/