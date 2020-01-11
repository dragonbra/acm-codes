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
int n,a[maxn],vis[maxn],ans=0;
void dfs(int x){
	if(x>n){
		if(n==1)ans++;
		int flag=0;
		for(int i=2;i<n;i++)
			if(abs(a[i]-a[i-1])==1 || abs(a[i]-a[i+1])==1)flag=1;
		if(abs(a[1]-a[2])==1 || abs(a[n]-a[1])==1)flag=1;
		if(!flag){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		a[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0; 
	}
}
int main(){
	scanf("%d",&n);
		a[1]=1;
		vis[1]=1;
		dfs(2);
		vis[1]=0;
	printf("%d\n",ans/2);
	return 0;
}
