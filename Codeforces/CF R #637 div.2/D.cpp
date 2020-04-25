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
int cst[210][10]; bool vis[N];
int nd[N], suf[N], suf2[N];

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
void dfs (int x, string s, int acc) {
    if (x==n+1) {
        if (acc == k) {
            f = true;
            cout << s << endl;
            //exit(0);
        }
        return;
    }
    if (acc > k) return;
    if (k-acc < suf[x] || suf2[x] < k-acc) return;
    for (int kk=9; kk>=0; kk--) {
        int cost = cst[num[x]][kk];
        if (cost == -1) continue;

        dfs (x+1, s+to_string(kk), acc + cost);

        if (f) return;
    }
}

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

    for (int i=1; i<=n; i++) {
        int mint = 10, maxt = 0;
        for (int j=0; j<=9; j++) {
            if(cst[num[i]][j]>=0) mint = min(mint, cst[num[i]][j]), maxt = max(maxt, cst[num[i]][j]);
        }
        suf[i] = mint; suf2[i] = maxt;
    }

    for (int i=n; i>=1; i--) {
        suf[i] = suf[i+1] + suf[i];
        suf2[i] = suf2[i+1] + suf2[i]; 
    }

    //for (int i=1; i<=n; i++) cout << suf[i] << ' ' << endl; cout << endl;

    string s = "";
    dfs(1,s,0);
    
    if (!f) cout << "-1" << endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/