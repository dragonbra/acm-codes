#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	
	while(T--){
		char sa[101],s[101];cin>>sa>>s;
		int len = strlen(s);
		int mm = (s[len-5]-'0')*10 + (s[len-4]-'0');
		int ss = (s[len-2]-'0')*10 + (s[len-1]-'0');
		//cout<<len<<' '<<ss<<' '<<mm<<endl;
		
		//int y = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
		//cout<<y<<endl;
		int ans=(60-ss); mm+=1; ans+=(60-mm)*60; ans%=100;
		//if(y<2050) ans = 100-ss;
		//else ans = ss;
		cout<<ans<<endl;
	}
	return 0;
}
