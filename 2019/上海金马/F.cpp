#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long a[1000010];

int main(){
	int w,q;cin>>w>>q;
	a[1]=1;
	for(int i=2;i<=1000010;i++){
		a[i]=a[i-1]*(i*2-1);a[i]%=mod;
	}
	while(q--){
		int n;
		cin>>n;
		long long ans = a[n];
		ans*=w;ans%=mod;
		cout<<ans<<endl;
	}
	return 0;
}
