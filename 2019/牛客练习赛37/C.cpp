#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a[21][21];int n=20;
	for(int i=1;i<=n;i++) a[i][1]=a[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++) a[i][j] = a[i-1][j]+a[i][j-1];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
		cout<<endl;
	}
	cout<<a[20][20];
	return 0;
}
