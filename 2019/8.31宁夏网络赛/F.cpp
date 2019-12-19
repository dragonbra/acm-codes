#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

const int MAXN=205;
int r[MAXN],idx[MAXN],dp[MAXN][MAXN][MAXN];
int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&r[i]),idx[i]=i;
        sort(idx+1,idx+n+1,[](int x,int y){return r[x]<r[y];});
        sort(r+1,r+n+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&dp[0][i][j]);
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp[k][i][j]=min(dp[k-1][i][j],dp[k-1][i][idx[k]]+dp[k-1][idx[k]][j]);
        printf("Case #%d:\n",ca);
        for(int i=1;i<=q;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            int k=upper_bound(r+1,r+n+1,w)-r-1;
            printf("%d\n",dp[k][u][v]);
        }
    }
    return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

