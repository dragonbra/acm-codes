#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+7;
ll quickpow(ll n,ll k)
{
	ll res=1,base=n;
	while(k)
	{
		if(k&1)
		{
			(res*=base)%=mod;
		}
		(base*=base)%=mod;
		k>>=1;
	}
	return res;
}

const int maxn=100005;
bool vis[maxn];
int primes[maxn];


int main()
{
	ll x,n;
	cin>>x>>n;
	int m=sqrt(x)+0.5;
	int mm=sqrt(m)+0.5;
	for(int i=2; i<=mm; i++)
	{
		if(!vis[i])
		{
			for(int j=i*i; j<=m; j+=i)
			{
				vis[j]=true;
			}
		}
	}
	int cnt=0;
	for(int i=2; i<=m; i++)
	{
		if(!vis[i])
		{
			primes[cnt++]=i;
		}
	}
	int t=x;
	int cur=0;
	ll ans=1;
	while(t>1&&cur<cnt)
	{
		if(t%primes[cur]==0)
		{
			while(t%primes[cur]==0)
			{
				t/=primes[cur];
			}
			ll u=primes[cur],v=u;
			while(1)
			{
				(ans*=quickpow(u,n/v))%=mod;
				if(v<=n/u)
					v*=u;
				else
					break;
			}
		}
		cur++;
	}
	if(t>1)
	{
		ll u=t,v=u;
		while(1)
		{
			(ans*=quickpow(u,n/v))%=mod;
			if(v<=n/u)
				v*=u;
			else
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

