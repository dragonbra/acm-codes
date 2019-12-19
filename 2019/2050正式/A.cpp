#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		char s[100010];
		cin>>s;
		int len = strlen(s);bool flag = true;
		for(int i=0;i<len;i++){
			if(i%4==0&&s[i]=='2') continue;
			else if(i%4==1&&s[i]=='0') continue;
			else if(i%4==2&&s[i]=='5') continue;
			else if(i%4==3&&s[i]=='0') continue;
			else{
				flag=false;break;
			}
		}
		if(len%4!=0) flag=false;
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
