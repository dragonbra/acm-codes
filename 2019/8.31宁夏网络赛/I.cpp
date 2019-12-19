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

int pw[55];
int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        k=min(n,k);
        for(int i=(pw[0]=1);i<=n;i++)
            pw[i]=1LL*(k+1)*pw[i-1]%q;
        int res=pw[n-k];
        for(int i=2;i<=n-k;i++)
            res=(res+1LL*(n-k+1-i)*pw[n-k+1-i])%q;
        for(int i=3;i<=n-k;i++)
            res=(res+1LL*(n-k+1-i)*pw[n-k-1])%q;
        for(int i=1;i<=k;i++)
            res=1LL*i*res%q;
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

