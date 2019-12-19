#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
bool f[maxn][128],vis[128];
int s[maxn],fst[maxn],nxt[maxn],ans[128];
char ss[maxn];
 
int main(){
	scanf("%s",ss);
	int n=strlen(ss),cnt=0;
	for (int i=n;i>=1;i--)
	{
		s[i]=ss[i-1];
		if (!vis[s[i]])
		{
			cnt++;
			vis[s[i]]=1;
		}
	}
	memset(vis,0,sizeof(vis));
	f[n][s[n]]=1;
	fst[s[n]]=n;
	for (int i=n-1;i>=1;i--)
	{
		for (int j=33;j<=126;j++)
			f[i][j]=f[i+1][j];
		f[i][s[i]]=1;
		nxt[i]=fst[s[i]];
		fst[s[i]]=i;
	}
	int mk=0;
	for(int i=1;i<=cnt;i++){
		for(int j=33;j<=126;j++){
			if (vis[j]) continue;
			
			while(fst[j]&&fst[j]<=mk) fst[j]=nxt[fst[j]];
			
			int sum=0;
			for(int k=33;k<=126;k++)
				if(!vis[k]&&f[fst[j]][k]) sum++;
			if (sum==cnt-i+1){
				ans[i]=j;
				vis[j]=1;
				mk=fst[j];
				break;
			}
		}
	}
	for(int i=1;i<=cnt;i++) printf("%c",ans[i]);
	return 0;
}
