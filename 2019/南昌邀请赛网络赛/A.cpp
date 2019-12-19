#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt = 0;int n=33550335;
	while(1){
		int ans=1;
		for(int i=2;i*i<=n;i++) if(n%i==0) ans+=i,ans+=n/i;
		if(ans==n){
			cnt++;
			cout<<n<<endl;
		}
		n++;
	}
	return 0;
}
