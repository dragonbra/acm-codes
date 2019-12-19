#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int main(){
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%s",s);
		int len = strlen(s);
		for(int j=0;j<len-1;j++){
			if(s[j]=='.'&&s[j+1]=='.') printf("C");
			else printf("D");
		}
		printf("\n");
	}
	return 0;
}
