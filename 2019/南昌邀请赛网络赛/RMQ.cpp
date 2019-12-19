#include<bits\stdc++.h>
using namespace std;
const int maxn = 100000+100;
int n;
int L[maxn],R[maxn];
int dmax[maxn][20];
int dmin[maxn][20];
int d[maxn];
void initmax(int n,int d[])
{
	for (int i = 1;i<=n;i++)
		dmax[i][0]=d[i];
	for (int j = 1;(1<<j)<=n;j++)
		for (int i = 1;i+(1<<j)-1<=n;i++)
			dmax[i][j]=max(dmax[i][j-1],dmax[i+(1<<(j-1))][j-1]);
}
int getmax(int L,int R)
{
	int k = 0;
	while ((1<<(k+1)) <= R-L+1)
		k++;
	return max(dmax[L][k],dmax[R-(1<<k)+1][k]);
}
 
void initmin(int n,int d[])
{
	for (int i = 1;i<=n;i++)
		dmin[i][0]=d[i];
	for (int j = 1;(1<<j)<=n;j++)
		for (int i = 1;i+(1<<j)-1<=n;i++)
			dmin[i][j]=min(dmin[i][j-1],dmin[i+(1<<(j-1))][j-1]);
}
int getmin(int L,int R)
{
	int k = 0;
	while ((1<<(k+1)) <= R-L+1)
		k++;
	return min(dmin[L][k],dmin[R-(1<<k)+1][k]);
}
 
int main()
{
    int q;
	int ans = 0;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%d",&d[i]);
    initmax(n,d);
	initmin(n,d);
    for(int i = 1;i<=n;i++)
	{
		int l = 1,r=i;
		while(l<=r)
		{
			int m = (l+r)>>1;
			if (abs(d[i]-getmin(m,i))<=0 && abs(d[i]-getmax(m,i))<=1)
				r=m-1;
			else
				l=m+1;
		}
		L[i]=l;
        l=i,r=n;
		while(l<=r)
		{
			int m = (l+r)>>1;
			if (abs(d[i]-getmin(i,m))<=0&&abs(d[i]-getmax(i,m))<=1)l=m+1;
			else
				r=m-1;
		}
		R[i]=l-1;
	}
	for(int i = 1;i<=n;i++)
		ans = max(ans,R[i]-L[i]+1);
	printf("%d\n",ans);
}
