#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;long long n,m,k,a,b,c;
	while(T--){
		cin>>n>>m>>k>>a>>b>>c;if(a>b) a=b;
		long long f[2010];for(int i=1;i<=2001;i++) f[i]=1e15; f[0]=0;
		for(int i=0;i<=2001;i++){
			f[i+1] = min( f[i+1] , f[i] + a);
			f[i+2] = min( f[i+2] , f[i] + a);
			f[i+3] = min( f[i+3] , f[i] + b);
		}
		long long ans = 1e15;//cout<<ans<<endl;
		for(int i=0;i<=k;i++){//i¼äÇéÂÂ·¿ 
			ans = min( ans , f[n+k-i] + f[m+k-i] + i*c );
		}
		cout<<ans<<endl;
	}
	return 0;
}
