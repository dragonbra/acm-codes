#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,k;
string a[N]; int num[N];
string mk[10] = {"1110111","0010010","1011101","1011011","0111010",
                 "1101011","1101111","1010010","1111111","1111011"};
int cst[210][10];
bool dp[N][N];

int cal(string s, int kk) {
    int res = 0;
    for (int i=0; i<7; i++) {
        if (s[i]=='0' && mk[kk][i]=='1') res++;
        if (s[i]=='1' && mk[kk][i]=='0') return -1; 
    }
    //cout << s << endl << mk[k] << ' ' << res << endl << endl;
    return res;
}

int calNum(string s) {
    int res = 0; int x = 1;
    for (int i=6; i>=0; i--) {
        if (s[i]=='1') res += x;
        x *= 2;
    }
    return res;
}

bool f = false;

int main() {
    redirect();

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i], num[i] = calNum(a[i]);
    
    for (int i=0; i<=127; i++) {
        string s="0000000";
        int t = i;
        for (int j=6; j>=0; j--) {
            if (t%2) s[j] = '1';
            t /= 2;
        }
        for (int j=0; j<=9; j++) {
            cst[i][j] = cal(s,j);
        }
        // cout << s << endl;
    }

    dp[n][k] = true;
    for (int i=n; i>=1; i--) {
        for (int j=k; j>=0; j--) {
            if (!dp[i][j]) continue;
            for (int kk=0; kk<=9; kk++) {
                int cost = cst[num[i]][kk];
                if (cost!=-1 && j>=cost) {
                    dp[i-1][j-cost] = true;
                }
            }
        }
    }

    string ans = ""; int res = 0;
    for (int i=0; i<n; i++) {
        int x = i+1;
        for (int kk=9; kk>=0; kk--) {

            int cost = cst[num[x]][kk];

            if (cost!=-1 && dp[x][ res + cost ] ) {
                //cout << ans << " " << kk << endl;
                res = res + cost;
                ans += to_string(kk);
                break;
            }
        }
    }

    
    if (!dp[0][0]) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/