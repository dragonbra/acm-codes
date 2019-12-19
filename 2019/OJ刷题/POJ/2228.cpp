#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int N = 4e3+10;

int n,b;
int u[N];int dp[2][2][N];//dir 3 

int main(){
	while(~scanf("%d%d",&n,&b)){
		for(int i=1;i<=n;i++) scanf("%d",&u[i]);
	
		int ans=0;
		//u[1] awake
		memset(dp,-inf,sizeof(dp));dp[0][1][0]=dp[1][1][1]=0;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=i;j++){
				dp[0][i&1][j]=max(dp[0][(i-1)&1][j],dp[1][(i-1)&1][j]);
				if(j>=1) dp[1][i&1][j]=max(dp[0][(i-1)&1][j-1],dp[1][(i-1)&1][j-1]+u[i]);
			}
		}
		ans=max(ans,max(dp[1][n&1][b],dp[0][n&1][b]));
		//printf("%lld\n",ans);
		
		//u[1] sleep
		memset(dp,-inf,sizeof(dp));dp[1][1][1]=u[1];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[0][i&1][j]=max(dp[0][(i-1)&1][j],dp[1][(i-1)&1][j]);
				if(j>=1) dp[1][i&1][j]=max(dp[0][(i-1)&1][j-1],dp[1][(i-1)&1][j-1]+u[i]);
			}
		}
		ans=max(ans,dp[1][n&1][b]);
		
		printf("%d\n",ans);
	}
	
}
