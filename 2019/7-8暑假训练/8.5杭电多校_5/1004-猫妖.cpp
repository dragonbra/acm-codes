#include<bits/stdc++.h>
#define maxn 25
using namespace std;
int n,k;
bool used[maxn<<1]= {0};
int c[maxn];

void print(int lb)
{
	int base=n-lb+1;
	cout<<base;
	for(int i=0; i<n-1; i++)
	{
		cout<<" "<<(base+=c[i]);
	}
	cout<<"\n";
}

void dfs(int cur,int x,int ub,int lb)
{
	if(cur==n-1)
	{
		if(--k==0)
		{
			print(lb);
		}
		return;
	}
	used[x]=true;
	for(int i=1-n; i<=n-1; i++)
	{
		if(k==0)
		{
			used[x]=false;
			return;
		}
		if(x+i-lb>=n||ub-(x+i)>=n||used[x+i])
		{
			continue;
		}
		c[cur]=i;
		dfs(cur+1,x+i,max(ub,x+i),min(lb,x+i));
	}
	used[x]=false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		dfs(0,n,n,n);
	}
}

