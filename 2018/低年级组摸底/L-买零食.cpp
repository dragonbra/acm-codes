#include <bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int w,v;
		cin>>w>>v;
		for(int j=m;j-w>=0;j--){
			a[j]=max(a[j],a[j-w]+v);
		}
	}
	cout<<a[m]<<endl;
}
