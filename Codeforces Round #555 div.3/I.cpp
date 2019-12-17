#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[10010],b[10010];

int main(){
	int T;
	while(cin>>T){
		while(T--){
		cin>>a>>b;
		int len1 = strlen(a);
		int len2 = strlen(b);
		int suma=0,sumb=0;
		for(int i=0;i<len1;i++) suma+=a[i]-'0';
		for(int i=0;i<len2;i++) sumb+=b[i]-'0';
		suma+=2;
		if(suma%3==1) suma = 1;
		else suma = 0;
		if(sumb%3==1) sumb = 1;
		else sumb = 0;
		if(suma==sumb) cout<<"0\n";
		else cout<<"1\n";
		}
	}
	return 0;
} 
