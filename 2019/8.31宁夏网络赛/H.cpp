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

const int MAXN=100005;
ll hp[MAXN],atk[MAXN];
int ord[MAXN];
ll K(ll h)
{
    ll l=0,r=h;
    while(l<r)
    {
        ll m=(l+r)/2;
        if(m*(m+1)/2>=h)r=m;
        else l=m+1;
    }
    return l;
}
int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&hp[i],&atk[i]);
        for(int i=1;i<=n;i++)
            hp[i]=K(hp[i]),ord[i]=i;
        sort(ord+1,ord+n+1,[](int x,int y){return hp[x]*atk[y]<hp[y]*atk[x];});
        ll sum=0,res=0;
        for(int i=1;i<=n;i++)
            sum+=atk[i];
        for(int ii=1;ii<=n;ii++)
        {
            int i=ord[ii];
            res+=hp[i]*sum;
            sum-=atk[i];
        }
        printf("Case #%d: %lld\n",ca,res);
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

