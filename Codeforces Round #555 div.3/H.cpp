#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll a[maxn];bool is[maxn];int T;int n;

int main(){
	while(~scanf("%d",&T)){
		while(T--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			
			int cnt = 0;is[n]=is[0]=false; 
			for(int i=2;i<=n-1;i++){
				if(a[i]>a[i-1]&&a[i]>a[i+1]){
					is[i]=true;cnt++;
				}
				else is[i]=false;
			}
			
			int cmp = 0;
			for(int i=1;i<=n;i++){
				int t = is[i-1]+is[i]+is[i+1]; int temp = 0;
				if( i>2 && a[i-1]>a[i-2] && a[i-1]>a[i+1] ) temp++;
				if( i<n-1 && a[i+1]>a[i-1] && a[i+1]>a[i+2] ) temp++;
				cmp = max(cmp,t-temp);
			}
			
			int ans = cnt-cmp;
			printf("%d\n",ans);
		}
	}
	return 0;
} 
