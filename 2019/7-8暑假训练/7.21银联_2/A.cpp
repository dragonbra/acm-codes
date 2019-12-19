#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int a[N][N];int dp[N][N];
int ans=0;int n,m;int T;

int main(){
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		ans=0; 
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char t;cin>>t;
				if(t=='*') a[i][j]=1;
				else if(t=='.') a[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==0){
					dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
					ans = max(ans,dp[i][j]);
				}
			}
		}
		cout<<ans*ans<<endl;
	}
	return 0;
}
