#include <bits/stdc++.h>
using namespace std;
char a[10010][11];

int main(){
	int n,x=0,y=0;char d[11];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d;
		if(d[0]=='J') {cin>>a[y];y++;}
		else if(d[0]=='Q') {cout<<a[--y]<<endl;}
		else if(d[0]=='P') {cout<<a[x++]<<endl;}
	}
}
