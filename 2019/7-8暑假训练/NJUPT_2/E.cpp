#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
int a[22];
 struct DP
{
    ll wei[10],sum;
    DP(){memset(wei,0,sizeof(wei));}
    DP(ll su):sum(su){memset(wei,0,sizeof(wei));}
}dp[20][2],ans[2];
 
DP sove(int pos,int lead,int limit)
{
 
    if(pos==-1)return DP(1);
    if(!limit&&~dp[pos][lead].sum)return dp[pos][lead];
    int end=limit?a[pos]:9;
    DP now(0);
    for(int i=0;i<=end;i++)
    {
 
        DP t=sove(pos-1,lead&&!i,limit&&i==a[pos]);
        for(int j=0;j<10;j++)
        {
            now.wei[j]+=t.wei[j];
 
        }
            now.sum+=t.sum;
            if(!lead||lead&&i)now.wei[i]+=t.sum;
 
    }
 
    if(!limit)dp[pos][lead]=now;
 
    return now;
}
 
void go(ll x,int k)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    ans[k]=sove(pos-1,1,1);
}
int main()
{
        ll m,n;
 
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<=1;j++)
            {
                dp[i][j].sum=-1;
            }
        }
        int T;scanf("%d",&T);
        while(T--)
        {
        	scanf("%lld%lld",&m,&n);
	 
	       memset(ans,0,sizeof(ans));
	        go(n,0);
	        go(m-1,1);
	 
	 		ll cnt=0;
	        for(int i=0;i<=9;i++)
	        {
	 			cnt+=((ans[0].wei[i]-ans[1].wei[i])%9*i%9);
	 			cnt%=9;
	        }
 			printf("%lld\n",cnt);
        }
 
 
    return 0;
}
