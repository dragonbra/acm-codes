#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,a[N];
int dp[N][N], dp2[N];

int main() {
    redirect();

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i]; 
        dp[i][i] = a[i];
    }

    for (int i=n-1; i>=1; i--) {
        for (int j=i+1; j<=n; j++) {
            dp[i][j] = -1;
            for (int k=i; k<j; k++) {
                if( dp[i][k]!=-1 && dp[i][k] == dp[k+1][j] ) {
                    dp[i][j] = dp[i][k] + 1;
                    // cout << i << j << dp[i][j] << endl;
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        dp2[i] = INF;
        for (int j=1; j<=i; j++) {
            if (dp[j][i]!=-1)
                dp2[i] = min(dp2[i], dp2[j-1]+1);
        }
    }

    cout << dp2[n] << endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/