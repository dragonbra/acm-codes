#include <bits/stdc++.h>
using namespace std;
char a[500010];int c[500010];
int main(){
	scanf("%s",a);
	int len = strlen(a);
	int st=-1,ed=-1;
	int cnt = 0;//[::]//[:|:]|
	for(int i=0;i<len;i++){
		if(cnt==0){
			if(a[i]=='[') st=i,cnt++;
		}
		else if(cnt==1){
			if(a[i]==':') cnt++;
		}
		else if(cnt==2){
			if(a[i]==':') cnt++;
		}
		else if(cnt==3){
			if(a[i]==']') ed=i,cnt++;
		}
		else if(cnt==4){
			if(a[i]==']') ed=i;
		}
	}
	
	int s=-1,e=-1;
	for(int i=0;i<len;i++){
		if(a[i]=='|') c[i]=c[i-1]+1;
		else c[i]=c[i-1];
		
		if(a[i]==':'&&(i>st&&i<ed)){
			if(s==-1) s=i,e=i;
			e=max(i,e);
		}
	}
	
	int ans=c[e]-c[s]+4;
	if(cnt==4) cout<<ans<<endl;
	else cout<<"-1"<<endl;
	
	return 0;
}
