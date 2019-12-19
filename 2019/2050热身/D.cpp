#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1) cout<<'0'<<endl;
		else cout<<(n-1)*(n-1)+1;
	}
	return 0;
}
