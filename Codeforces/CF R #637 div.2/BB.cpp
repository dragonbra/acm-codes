#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
const int Maxn=5e5+10;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int a[N],b[N],c[N];
int n,k;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		b[0]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=0,c[i]=0;
		for(int i=2;i<n;i++)
			if(a[i]>a[i-1] && a[i]>a[i+1])b[i]=1;
		int ans=0,l=n;
		for(int i=1;i<=n;i++)c[i]=c[i-1]+b[i];
		for(int i=1;i<=n-k+1;i++){
			int r=i+k-1;
			int num=c[r]-c[i-1];
			if(b[i]==1 && b[r]==1)num-=2;
			else if(b[i]==1 && b[r]!=1)num--;
			else if(b[i]!=1 && b[r]==1)num--;
			if(num>ans){
				ans=num;
				l=i;
			}else if(num==ans && i<l)l=i;
			
		}
		printf("%d %d\n",ans+1,l);
	}
	return 0;
}
