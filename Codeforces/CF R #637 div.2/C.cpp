#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T, n;
int a[N], pos[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        scanf("%d",&n);
        for (int i=1; i<=n; i++) scanf("%d",&a[i]), pos[a[i]] = i;

        int lst = n+1; bool f = true;
        for (int i=1; i<=n; i++) {
            int t = pos[i];
            if (t<lst || t==lst+1) {
                if (t<lst) lst = t;
                else lst ++;
            } else {
                //cout << i <<' '<< pos[i] <<' '<< lst << endl;
                f = false;
                break;
            }
        }

        if (f) puts("Yes");
        else puts("No");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/