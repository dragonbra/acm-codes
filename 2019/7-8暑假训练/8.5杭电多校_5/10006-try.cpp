#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1010];int a[1010];int cnt=0;

int main(){
	int T;cin>>T;
	while(T--){
		cnt=0;
		cin>>s;
		int len = strlen(s);
		for(int i=1;i<len;i++){
			int k=0;
			while(i+k<len){
				cnt++;
				if(s[k]==s[i+k]){
					k++;
				}
				else break;
			}
			a[i]=k;
		}
		cout<<len-1<<' '<<cnt<<endl;
		for(int i=0;i<len;i++) cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}
