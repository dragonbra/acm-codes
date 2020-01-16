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

int n,k,m;
bool a[5][N];//a[i][j] = 第i轮第j个人是否参加
int cnt[15];

int main() {
    redirect();

    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            int t; scanf("%d",&t);
            a[i][t] = true;
        }
    }

    int ans = 0;

    if(k==1){
        for(int i=1;i<=n;i++) ans += a[0][i];
    } else if(k==2){
        for(int i=1;i<=n;i++){
            int res = 1, x = 0;
            for(int j=0;j<3;j++){
                if(a[j][i]) x += res;
                res*=2;
            }
            cnt[x] ++ ;
        }
        ans = max( cnt[1] , cnt[2] ) + cnt[3];
    } else if(k==3){
        for(int i=1;i<=n;i++){
            int res = 1, x = 0;
            for(int j=0;j<3;j++){
                if(a[j][i]) x += res;
                res*=2;
            }
            cnt[x] ++ ;
        }

        cnt[1] = cnt[6] >= cnt[1] ? 0 : cnt[1]-cnt[6];
        cnt[2] = cnt[5] >= cnt[2] ? 0 : cnt[2]-cnt[5];
        cnt[4] = cnt[3] >= cnt[4] ? 0 : cnt[4]-cnt[3];
        ans = max( cnt[1], max( cnt[2], cnt[4] ) );
        ans += ( cnt[3] + cnt[5] + cnt[6] + cnt[7] );
    }

    printf("%d\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/