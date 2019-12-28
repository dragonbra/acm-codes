#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n;
ll s;
ll a[2020][2020],f[2020][2020];
int main(){
	scanf("%d%lld",&n,&s);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	int l=1,r=n,mid=0,flag=1,ans;
	while(l<=r){
		mid=(l+r)/2;
		int fflag=1;
		for(int i=mid;i<=n;i++){
			for(int j=mid;j<=n;j++){
				int ii=i-mid+1,jj=j-mid+1;
				if(f[i][j]+f[ii-1][jj-1]-f[ii-1][j]-f[i][jj-1]>=s){
					fflag=0;
					ans=mid;
					break;
				}
			}
			if(!fflag)break;
		}
		if(!fflag)flag=0;
		if(fflag)l=mid+1;
		else r=mid-1;
	}
	if(flag)puts("I'm a Gold Chef!");
	else printf("%d\n",ans);
	return 0;
}
