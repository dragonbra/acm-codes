#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
 
 
int n,m;
int a[maxn],b[maxn];
int f[maxn][20];//f[i][j]表示从i位起的2^j个数中的最大数，即[i,i+(1<<j)-1]
int df[maxn][20];
 
 
void ST_prewoek()
{
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	for(int i=1,imax=log2(n);i<=imax;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)//注意j的右端点为j+(1<<i)-1，-1是因为要包含j自己 
			f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
}

void ST_prewoek_2()
{
	for(int i=1;i<=n;i++) df[i][0]=b[i];
	for(int i=1,imax=log2(n);i<=imax;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)//注意j的右端点为j+(1<<i)-1，-1是因为要包含j自己 
			df[j][i]=min(df[j][i-1],df[j+(1<<i-1)][i-1]);
}
 
 
int ST_query(int l,int r)//求[l,r]中的最大值 
{
	int k=log2(r-l+1);//区间长度r-l+1 
	return max(f[l][k],f[r-(1<<k)+1][k]);//第1个区间：[l,l+(1<<k)-1]；第2个区间：[r,(1<<k)+1~r]
}

int ST_query(int l,int r)//求[l,r]中的最大值 
{
	int k=log2(r-l+1);//区间长度r-l+1 
	return min(f[l][k],f[r-(1<<k)+1][k]);//第1个区间：[l,l+(1<<k)-1]；第2个区间：[r,(1<<k)+1~r]
}


 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ST_prewoek();
	ST_prewoek_2();
	while(m--)
	{
		int l,r,ans;
		scanf("%d%d",&l,&r);
		ans=ST_query(l,r);
		printf("%d\n",ans);
	}
	return 0;
}
