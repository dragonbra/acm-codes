#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 110 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,m,W;
int cnt[N][N], sol[N][N];
int lc[N][N], k[N][N];
int ans[N];

int main() {
    redirect();

    scanf("%d%d%d",&n,&m,&W);
    int lx=0, ly=0;
    for(int i=1;i<=W;i++){
        int x,y,c; scanf("%d%d%d",&x,&y,&c);
        if(c==0) {
            if(c==lc[x][y]) k[x][y]++, cnt[x][y] = max(cnt[x][y],k[x][y]);
            else k[x][y] = 1, cnt[x][y] = max(cnt[x][y],k[x][y]);
            cnt[x][0]++;
        }//cnt[x][0] x的错误提交次数
        else if(c==1){
            k[x][y]=0;
            if(sol[x][y]==0) sol[x][y]=1, sol[x][0]++, sol[0][y]++;
        }
        //sol[x][0] x的解题数 sol[0][y] y题正确的人数
        lx = x, ly = y, lc[x][y] = c;
    }

    for(int i=1;i<=n;i++){
        if( cnt[i][0] + sol[i][0] == 0 ) ans[i] = 998244353;
        else if( sol[i][0] == 0 ) ans[i] = 1000000;
        else if( sol[i][0] == m ) ans[i] = 0;
        else{
            for(int j=1;j<=m;j++){
                if( sol[0][j]>0 && sol[i][j]==0 ) ans[i] += 20;
                if( sol[0][j]>=n/2 && sol[i][j]==0 ) ans[i] += 10;
                if( cnt[i][j] ) {
                    ans[i] += cnt[i][j] * cnt[i][j];
                    if( sol[i][j]==0 ) ans[i] += cnt[i][j] * cnt[i][j]; 
                }
            }
        }
    }

    for(int i=1;i<=n;i++) {
        printf("%d",ans[i]);
        if(i!=n) printf("\n");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/