#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3010;
const int mod = 998244353;
ll c[N][N];int s1[N],s2[N],dp[N][2];

void init(){
	for(int i=0;i<=3000;i++) c[i][0]=c[i][i]=1;
	for(int i=2;i<=3000;i++){
		for(int j=1;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
}

int main(){
	init();
	int T;scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		char t1[N],t2[N];
		scanf("%s%s",t1,t2);
		for(int i=0;i<n;i++) s1[i+1]=t1[i]-'0';
		for(int i=0;i<m;i++) s2[i+1]=t2[i]-'0';
		
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(s1[i]==s2[j]) dp[j][0]=(dp[j][0]+dp[j-1][0])%mod;
				dp[j][1]=(dp[j][1]+dp[j-1][1])%mod;
				if(s1[i]<s2[j]) dp[j][1]=(dp[j][1]+dp[j-1][0])%mod;
			}
		}
		
		/*for(int i=0;i<=1;i++){
			for(int j=1;j<=m;j++) cout<<dp[j][i]<<' ';
			cout<<endl;
		}*/ 
		
		
		
		ll ans=0;
		for(int i=m;i<=n;i++){
			ans+=c[n][i];ans%=mod;
		}
		ans-=(dp[m][0]+dp[m][1]);
		//cout<<endl<<(dp[m][0]+dp[m][1])<<endl<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
