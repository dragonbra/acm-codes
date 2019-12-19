#include <bits/stdc++.h>
using namespace std;
long long f[1001][1001];
long long a[1001],b[1001],c[1001];
int T;int n,cc;

int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>cc;memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		f[0][0]=cc;
		for(int j=0;j<=n-1;j++){
			for(int i=0;i<=j;i++){
				if(f[i][j]>0){
					if( min( f[i][j] , b[j+1] ) > a[j+1] ) 
						f[i+1][j+1] = max( min( f[i][j] , b[j+1] ) - a[j+1] + c[j+1] , f[i+1][j+1] );
					f[i][j+1] = max( f[i][j] + c[j+1] , f[i][j+1] );
				}
			}
		}
		int ans = 0;
		for(int i=0;i<=n;i++){
			if(f[i][n]>0) ans = i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
