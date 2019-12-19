#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char s[N];int a[N],c[N];

int main(){
	cin>>s;
	int len = strlen(s);
	for(int i=0;i<len;i++){
		a[i]=s[i]-'0';
	}
	
	int cnt=0;long long ans=0;
	for(int i=0;i<len;i++){
		if(a[i]==0){
			cnt++;ans++;
		}
		else cnt=0;
		
		if(cnt>=2){
			ans+=c[0];
		}
		
		int t1=c[1],t2=c[2],t0=c[0];
		c[(1+a[i])%3]=t1;
		c[(2+a[i])%3]=t2;
		c[(0+a[i])%3]=t0+1;
		
		cout<<i<<' '<<c[0]<<' '<<c[1]<<' '<<c[2]<<"========="<<ans<<endl; 
	}
	
	cout<<ans<<endl;
	
	return 0;
}
