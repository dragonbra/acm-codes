#include <bits/stdc++.h>
using namespace std;

int main(){
	long long l,r,d;
	int q;
	cin>>q;
	while(q--){
		cin>>l>>r>>d;
		if(d>=l&&d<=r){
			d = (r/d+1)*d;
		}
		cout<<d<<endl;
	} 
	return 0;
}
