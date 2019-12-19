#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL cmp = pow(2,31);

int get1(LL a){
	int cnt=0;
	while(a){
		if(a%2==1) cnt++;
		a/=2;
	}
	return cnt;
}

int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		LL t;cin>>t;
		if(t>=0) cout<<get1(t)<<endl;
		else cout<<get1(cmp-abs(t))+1<<endl;
	}
	
}
