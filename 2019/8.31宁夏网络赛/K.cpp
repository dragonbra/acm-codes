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

const int MAXN=18;
int a[MAXN<<1],ltl[MAXN],ltr[MAXN],rtr[MAXN],sum[1<<MAXN];
int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int lef=(n+1)/2,rig=n-lef;
        for(int i=0;i<lef;i++)
            ltl[i]=ltr[i]=0;
        for(int i=0;i<rig;i++)
            rtr[i]=0;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            if(u>v)swap(u,v);
            if(u<lef)
            {
                if(v<lef)ltl[u]|=1<<v;
                else ltr[u]|=1<<(v-lef);
            }
            else rtr[u-lef]|=1<<(v-lef);
        }
        for(int i=0;i<(1<<rig);i++)
        {
            int prod=1;
            for(int j=0;j<rig;j++)
            {
                if(i>>j&1)prod=1LL*prod*a[j+lef]%q;
                else prod*=((rtr[j]|i)==i);
            }
            sum[i]=prod;
        }
        for(int i=0;i<rig;i++)
            for(int j=0;j<(1<<rig);j++)
                if(~j>>i&1)sum[j]=(sum[j]+sum[j|(1<<i)])%q;
        int res=0;
        for(int i=0;i<(1<<lef);i++)
        {
            int prod=1,need=0;
            for(int j=0;j<lef;j++)
            {
                if(i>>j&1)prod=1LL*prod*a[j]%q;
                else prod*=((ltl[j]|i)==i),need|=ltr[j];
            }
            res=(res+1LL*prod*sum[need])%q;
        }
        printf("Case #%d: %d\n",ca,res);
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

