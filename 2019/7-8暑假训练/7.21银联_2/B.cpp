#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
int n,m;

int main(){
	LL sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum+=(i*j*(n%i)*(m%j));sum%=mod;
		}
	}
	cout<<sum<<endl;
	return 0;
}
