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

int n,k; int pos[27][N]; int cnt[27];
char s[N];

int main() {
    redirect();

    scanf("%d%d",&n,&k);
    scanf("%s",s);

    int ans = INF;
    for(int i=0;i<n;i++){
        int t = s[i]-'a'+1;
        cnt [t] ++;
        pos [t] [ cnt[t] ] = i+1;
    }

    for(int i=1;i<=26;i++){
        for(int j=k;j<=cnt[i];j++){
            //cout<<(char) (i+'a'-1)<<' '<<pos[i][j] - pos[i][j-k+1] + 1 <<endl;
            ans = min( ans, pos[i][j] - pos[i][j-k+1] + 1 );
        }
    }
    //cout<<pos[2][1]<<' '<<pos[2][2]<<endl;

    if( ans == INF ) puts("-1");
    else cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/