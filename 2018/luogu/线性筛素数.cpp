#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8+10;
const int maxm = 1e5+10;
bool vis[maxn];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int end = sqrt(n+0.5);
	
	vis[1]=1; 
	for(int i=2;i<=end;i++)	if(!vis[i]) for(int j=i*i;j<=n;j+=i) vis[j]=1;
	
	for(int i=1;i<=m;i++){
		int ask;scanf("%d",&ask);
		if(vis[ask]) printf("No\n");
		else printf("Yes\n");
	}
	
}
