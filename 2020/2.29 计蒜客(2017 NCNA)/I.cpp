#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 120 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T;
map<char,int> a;
char s[N];

int main() {
    redirect();

    for(int i=1;i<=26;i++){
        a['A'+i-1] = i;
    }
    a[' '] = 27;
    a['\''] = 28;
    double dis = 3.1415926535 * 60 / 28;

    scanf("%d",&T); getchar();
    while(T--){
        cin.getline(s,125);
        int len = strlen(s);

        int pos = s[0]; int cnt = 0;
        for(int i=1;i<len;i++){
            int cmp = abs( a[ s[i] ] - a[ s[i-1] ] );
            cnt += min( cmp, 28-cmp );
        }
        //cout<<cnt<<' '<<len<<endl;
        double ans = (double)cnt*dis / (double)15.0 + (double)len;
        printf("%.10lf\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/