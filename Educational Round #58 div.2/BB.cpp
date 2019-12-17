#include <bits/stdc++.h>
using namespace std;
char a[500010];
int main(){
	scanf("%s",a);
	int len = strlen(a);
	
	int cnt = 0; int ans = 0;//[::]
	for(int i=0;i<len;i++){
		if(cnt==0){
			if(a[i]=='['){
				cnt++;ans++;
			}
		}
		else if(cnt==1){
			if(a[i]==':'){
				cnt++;ans++;
			}
		}
		else if(cnt==2){
			if(a[i]==':'){
				cnt++;ans++;
			}
			else if(a[i]=='|') ans++;
		}
		else if(cnt==3){
			if(a[i]==']'){
				cnt++;ans++;break;
			}
		}
	}
	
	if(cnt==4) cout<<ans<<endl;
	else cout<<-1<<endl;
	
	return 0;
}
