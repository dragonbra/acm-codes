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
struct arr{
	int le,ri;
}f[maxn];
int n,d;
int vis[maxn];
bool cmp(arr a,arr b){
	if(a.ri==b.ri)return a.le<b.le;
	return a.ri<b.ri;
}
int main(){
	int cnt=0;
	while(~scanf("%d%d",&n,&d)){
		if(n+d==0)break;
		int flag=0;
		cnt++;
		for(int i=1;i<=n;i++){
			int x,y;
			vis[i]=0;
			scanf("%d%d",&x,&y);
			if(y<=d){
				f[i].le=x-sqrt(d*d-y*y);
				f[i].ri=x+sqrt(d*d-y*y);
			}else flag=1;
		}
		printf("Case %d: ",cnt); 
		if(flag)puts("-1");
		else{
			int ans=0;
			sort(f+1,f+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				ans++;
				for(int j=i+1;j<=n;j++)
					if(f[j].le<=f[i].ri)vis[j]=1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
