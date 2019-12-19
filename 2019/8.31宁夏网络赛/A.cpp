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

const int MAXN=5000005;

int stk[MAXN],top,res[MAXN];
int n, p, q, m;
unsigned int SA,SB,SC;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
long long solve()
{
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    long long res=(top=0);
    for(int i=1;i<=n;i++)
    {
        if(rng61()%(p+q)<p)
        {
            ++top;
            stk[top]=rng61()%m+1;
            stk[top]=max(stk[top],stk[top-1]);
        }
        else top=max(top-1,0);
        res^=1LL*i*stk[top];
    }
    return res;
}
int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1; ca<=T; ca++)
        printf("Case #%d: %lld\n",ca,solve());
    return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/
