#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	char s[5010];int a[5010];
	cin>>s;
	int len = strlen(s);
	for(int i=0;i<len;i++){
		a[i]=a[i-1];
		if(s[i]=='Q') a[i]++;
	}
	int cnt = a[len-1];ll ans = 0;
	
	for(int i=0;i<len;i++){
		if(s[i]=='A'){
			int l = a[i],r = cnt - a[i];//cout<<l<<' '<<r<<endl;
			if(s[i-1]=='Q') l--;
			if(s[i+1]=='Q') r--;
			ans += l*r;
		}
	}
	
	//cout<<cnt<<endl;
	cout<<ans<<endl;
	return 0;
}
