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
int n,m,ans;
struct arr{
	int x,y;
}a[22];
int d[22][22],f[1<<22][22];
map<string,int>mmap;
string s;
vector<int>v[22];
void dfs(int cnt,int x){
	if(cnt==m){
		ans=min(ans,f[x][0]);
		return;
	}
	for(int i=0;i<v[cnt+1].size();i++)
		dfs(cnt+1,(x|(1<<v[cnt+1][i])));
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		cin>>s;
		if(mmap.count(s))v[mmap[s]].push_back(i);
		else {
			mmap[s]=++m;
			v[mmap[s]].push_back(i);
		}
	} 
	a[0].x=0,a[0].y=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			d[i][j]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
	memset(f,INF,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<(1<<(n+1));i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				if((i & (1<<j))==0)
					f[i|(1<<j)][j]=min(f[i|(1<<j)][j],f[i][k]+d[k][j]);
	ans=INF;
	dfs(0,1);
	printf("%d\n",ans);			
	return 0;
}
