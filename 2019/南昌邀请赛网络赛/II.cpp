#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+10;//+=1e5;*;-=1e5*n;

int n;
ll a[maxn],sum[maxn],l[maxn],r[maxn];
ll dmax[maxn][20],dmin[maxn][20];

void initmax(int n,ll sum[])
{
	for(int i=0;i<=n;i++)
		dmax[i][0]=sum[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)-1<=n;i++)
			dmax[i][j]=max(dmax[i][j-1],dmax[i+(1<<(j-1))][j-1]);
}

ll getmax(int L,int R)
{
	int k=0;
	while( (1<<(k+1)) <= R-L+1 ) k++;
	return max(dmax[L][k],dmax[R-(1<<k)+1][k]);
}

void initmin(int n,ll sum[])
{
	for(int i=0;i<=n;i++)
		dmin[i][0]=sum[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)-1<=n;i++)
			dmin[i][j]=min(dmin[i][j-1],dmin[i+(1<<(j-1))][j-1]);
}

ll getmin(int L,int R)
{
	int k=0;
	while( (1<<(k+1)) <= R-L+1 ) k++;
	return min(dmin[L][k],dmin[R-(1<<k)+1][k]);
}

int main(){
	freopen("1.txt","r",stdin);
	freopen("22.txt","w",stdout);
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]); 
			sum[i]=sum[i-1]+a[i];l[i]=r[i]=i;
		}
		a[0]=a[n+1]=-maxn;
		
		for(int i=1;i<=n;i++){
			while(a[i]<=a[l[i]-1]) l[i]=l[l[i]-1];
		}
		
		for(int i=n;i>=1;i--){
			while(a[i]<=a[r[i]+1]) r[i]=r[r[i]+1];
		}
		
		//sum_RMQ();
		initmin(n,sum);
		initmax(n,sum);
		
		ll ans = 0;int mk=0;
		//cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			//cout<<l[i]<<' '<<r[i]<<endl;
			if(a[i]<0){
				//ans = max( ans , ( getmin(i,r[i]) - sum[i] ) * a[i] );
				//ans = max( ans , ( sum[i] - getmax(l[i]-1,i) ) * a[i]);
				/*
				ll cmp = 0;
				if(getmin(i+1,r[i])-sum[i]<0) cmp+=(getmin(i+1,r[i])-sum[i]);
				if(sum[i-1]-getmax(l[i]-1,i-1)<0) cmp+=(sum[i-1]-getmax(l[i]-1,i-1));
				ans=max(ans,(cmp+a[i])*a[i]);
				*/
				ll cmp = 0;
				ll left = sum[i]-getmax(l[i]-1,i);ll right = getmin(i,r[i])-sum[i];
				//cout<<left<<' '<<right<<endl;
				//cout<<l[i]<<' '<<r[i]<<endl;
				if(left<=0) cmp+=left;
				if(right<=0) cmp+=right;
				
				cmp*=a[i];
				if(cmp>ans){
					ans=cmp;mk = i;
				}
			}
			else if(a[i]>0){
				ll cmp = 0;
				ll left = sum[i]-getmin(l[i]-1,i);ll right = getmax(i,r[i])-sum[i];
				//cout<<left<<' '<<right<<endl;
				//cout<<l[i]<<' '<<r[i]<<endl;
				if(left>=0) cmp+=left;
				if(right>=0) cmp+=right;
				
				cmp*=a[i];
				if(cmp>ans){
					ans=cmp;mk = i;
				}
			}
		}
		//for(int i=1;i<=n;i++) cout<<sum[i]<<' ';cout<<endl;
		//cout<<getmax(0,7)<<endl;
		printf("%lld\n",ans);
		//cout<<mk<<endl;
	}
	return 0;
}
