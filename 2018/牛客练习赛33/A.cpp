#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	while(n--){
		long long l,r,x;
		cin>>l>>r>>x;
		long long ans = r/x-l/x;
		if(l%x==0) ans++;
		cout<<ans<<endl;
	} 
	return 0;
}
