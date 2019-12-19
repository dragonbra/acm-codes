#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		ll n;scanf("%lld",&n);
		
		ll ans=0;
		ll l=1,r=1e6+10;
		while(l<r){
			ll mid = (l+r)/2;
			if(mid*mid*mid>n) r=mid;
			else if(mid*mid*mid<=n){
				l=mid+1;
				if((mid+1)*(mid+1)*(mid+1)>n){
					ans=mid;
					break;
				}
			}
		}
		
		if((ans+1)*(ans+1)*(ans+1)<=(n+ans)) ans++;
		n+=ans;
		printf("%lld\n",n);
		
	}
	
	return 0;
}
