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

string s;

int main() {
    redirect();

    bool f = 0;

    cin >> s;
    double ans = 0; int res = 0; int cnt = 1 ;
    for (int i=0; i<=s.length(); i++) {
        if (s[i]>='0' && s[i]<='9') {
            res *= 10; res += s[i]-'0';
        } else if (s[i]=='d') {
            i++; cnt = 0; 
            while (s[i]>='0' && s[i]<='9') {
                cnt *= 10; cnt += s[i]-'0';
                i++;
            }
        }
        if (s[i]=='+' || i==s.length()) {
            if (cnt %2 == 0 && res %2 == 1) f = !f;
            ans += res * ((1.0+cnt)/2.0);
            res = 0; cnt = 1;
        } 
    }

    if (f) printf("%.1lf\n",ans);
    else printf("%d\n",int(ans));

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/