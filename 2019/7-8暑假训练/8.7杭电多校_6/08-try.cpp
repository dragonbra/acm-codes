#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {if(a<b)swap(a,b);return b?gcd(b,a%b):a;}

int main(){
	ll t;
	cin>>t;
	int cnt=0;
	for(int i=1;i<=6000;i++){
		if(gcd(t,t+i)==1) cnt++;
		if(cnt==100) cout<<t+i<<' '<<(t^i)<<endl;
	}
	return 0;
}

