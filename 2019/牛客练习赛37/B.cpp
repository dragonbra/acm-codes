#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long ff(int n){
	int x = n/2 - 1; 
	long long ans = 1;
	for(int i=x;i>=1;i-=2){
		ans*=i;ans%=mod;
	}
	int cmp = n/4;
	for(int i=1;i<=cmp;i++){
		ans*=2;ans%=mod;
	}
	return ans;
}
int main(){
	int n;cin>>n;
	if(n%4==0||n%4==1){
		cout<<ff(n)<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
