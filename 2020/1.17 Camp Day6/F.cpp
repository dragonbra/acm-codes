#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
vector <int> G[N];
vector <int> G2[N];
bool E[N][N], E2[N][N];
ll A,B,C,P,D;

int main() {
    redirect();

    scanf("%d",&n);
    scanf("%lld%lld%lld%lld%lld",&A,&B,&C,&P,&D);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if( ( A*(i+j)*(i+j) + B*(i-j)*(i-j) + C ) % P > D ) G[i].push_back(j), E[i][j]=1;
            else G2[i].push_back(j), E2[i][j]=1;
        }
    }

    ll ans = 0;
    for(int u=1;u<=n;u++){
        for(auto v:G[u])
            for(auto vv:G[v]){
                if(E[vv][u]) ans++;
            }
    }

    for(int u=1;u<=n;u++){
        for(auto v:G2[u])
            for(auto vv:G2[v]){
                if(E2[vv][u]) ans++;
            }
    }

    ans /= 6;
    printf("%lld\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/