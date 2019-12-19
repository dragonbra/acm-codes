#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,num;
}s[100010];

int n;
int d[100010];bool vis[100010];

bool cmp1(node a,node b){
	return a.b>b.b;
}

bool cmp2(node a,node b){
	return a.a<b.a;
}

int dfs(int x,int dpt){
	if(vis[x]==1) return dpt-1;
	vis[x]=1;
	if(x==d[x]) return 0;
	return dfs(d[x],dpt+1);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].a);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].b);
	}
	
	sort(s+1,s+n+1,cmp1);
	for(int i=1;i<=n;i++) s[i].num=i;
	sort(s+1,s+n+1,cmp2);
	for(int i=1;i<=n;i++) d[i]=s[i].num;
	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) ans+=dfs(i,0);
	}
	cout<<ans<<endl;
	return 0;
}
