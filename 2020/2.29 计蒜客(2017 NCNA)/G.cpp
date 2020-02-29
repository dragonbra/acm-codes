#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,m,ans,stx,sty;
int vis[110][110],tmp[110][110];
int dis[10][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
char s[110][110];

void dfs(int x,int y,int tot){
	int flag=0;
	for(int i=0;i<8;i++){
		int nx=x+dis[i][0],ny=y+dis[i][1];
		if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]!='#' || vis[nx][ny] || tmp[nx][ny])continue;
		vis[nx][ny]=1;
		tmp[nx][ny]=1;
		dfs(nx,ny,tot+1);
		vis[nx][ny]=0;
		flag=1;
	}
	if(!flag && tot>1){
		for(int i=0;i<8;i++){
			int nx=x+dis[i][0],ny=y+dis[i][1];
			if(nx==stx && ny==sty){
				ans++;
				return;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m); 
	for(int i=0;i<n;i++)scanf("%s",&s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			memset(vis,0,sizeof(vis));
			if(!vis[i][j] && s[i][j]=='#'){
				vis[i][j]=1;
				tmp[i][j]=1;
				stx=i,sty=j;
				dfs(i,j,1);
			}
		}
	printf("%d\n",ans);
	return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/