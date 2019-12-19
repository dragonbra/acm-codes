#include <bits/stdc++.h>
using namespace std;
int n,l,t;int ans=1;
int main(){
	cin>>n>>l>>t;
	for(int i=1;i<=n;i++){
		int x,d;
		cin>>x>>d;
		if(d==1){
			if(l-x>t) ans++;
		}
		else if(d==2){
			if(x>t) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
