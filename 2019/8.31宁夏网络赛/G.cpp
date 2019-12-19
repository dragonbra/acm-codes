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
#include <assert.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
const int MAXN=100005;
const int MAXK=105;
const ll INF=(1LL<<60)-1;
vector<pair<int,int> > e[MAXN];
ll dp[MAXN][MAXK],tmp[MAXK];
int sz[MAXN];
void dfs(int u,int f,int k)
{
    if((int)e[u].size()==1)
    {
        sz[u]=1,dp[u][0]=dp[u][1]=0;
        return;
    }
    sz[u]=0;
    for(auto &t:e[u])
    {
        int v=t.first,c=t.second;
        if(v==f)continue;
        dfs(v,u,k);
        int ts=min(k,sz[u]+sz[v]);
        for(int i=0;i<=ts;i++)
            tmp[i]=INF;
        for(int i=0;i<=sz[u];i++)
            for(int j=0;j<=sz[v] && i+j<=ts;j++)
                tmp[i+j]=min(tmp[i+j],dp[u][i]+dp[v][j]+j*(k-j)*c);
        for(int i=0;i<=ts;i++)
            dp[u][i]=tmp[i];
        sz[u]=ts;
    }
}

int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n-1;i++)
        {
            int u,w,v;
            scanf("%d%d%d",&u,&v,&w);
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }
        printf("Case #%d: ",ca);
        if(n==2)printf("%d\n",(k==2 ? e[1][0].second : 0));
        else
        {
            int rt=0;
            for(int i=1;i<=n;i++)
                if((int)e[i].size()>1)rt=i;
            assert(rt);
            dfs(rt,0,k);
            printf("%lld\n",dp[rt][k]);
        }
        for(int i=1;i<=n;i++)
            e[i].clear();
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

