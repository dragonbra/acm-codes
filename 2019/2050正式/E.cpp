#include <bits/stdc++.h>
using namespace std;
int f[10001][12][12];//[x][a][b]µÚx¸öÎÊºÅ a:b 
int pos[10010];
char s[10010];int cnt,len;int ans = 0;

void dfs(int x,int a,int b,int cc){//cc == cnt
	if(f[x][a][b]!=0) cc=f[x][a][b];
	else{
		for(int i=pos[x];i<pos[x+1];i++){
			if(a==10&&b==10){
				if(s[i]=='A') b--;
				if(s[i]=='B') a--;
			}
			else{
				if(s[i]=='A') a++;
				if(s[i]=='B') b++;
			}
			
			if(a==11){
				a=0;b=0;cc++;
			}
			if(b==11){
				a=0;b=0;cc++;
			}
		}
		f[x][a][b]=cc;
	}
	if(x==cnt){
		ans=max(ans,cc);return;
	}
	s[pos[x+1]]='A';dfs(x+1,a,b,cc);
	s[pos[x+1]]='B';dfs(x+1,a,b,cc);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		cin>>s;
		cnt = 0; len = strlen(s);
		
		for(int i=0;i<len;i++){
			if(s[i]=='?') pos[++cnt]=i;
		}pos[0]=0;pos[cnt+1]=len;
		cout<<ans<<endl;
	}
	return 0;
}
