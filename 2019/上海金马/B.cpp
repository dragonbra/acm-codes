#include <bits/stdc++.h>
using namespace std;
int s[27]; 
int n;

int main(){
	cin>>n;
	for(int i=1;i<=26;i++){
		char t;cin>>t;
		s[t-'a'+1]=i;
	}
	//for(int i=1;i<=26;i++) cout<<s[i]<<' ';
	while(n--){
		char a[1010],b[1010];
		cin>>a>>b;
		
		if(strcmp(a,b)==0) cout<<"="<<endl;
		else{
			int l1=strlen(a),l2=strlen(b);
			int flag=0;//0=>,1=<
			for(int i=0;i<l1&&i<l2;i++){
				if(i==l1-1&&l2>l1&&a[l1-1]==b[l1-1]){
					flag=1;break;
				}
				if(i==l2-1&&l1>l2&&a[l2-1]==b[l2-1]){
					flag=0;break;
				}
				
				if(s[a[i]-'a'+1]>s[b[i]-'a'+1]){
					flag=0;break;
				}
				else if(s[a[i]-'a'+1]<s[b[i]-'a'+1]){
					flag=1;break;
				}
			}
			if(flag) cout<<"<"<<endl;
			else cout<<">"<<endl;
		}
	} 
	return 0;
}
