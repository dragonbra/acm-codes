#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N]={0};

int main(){
	int n;cin>>n;
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		a[u]++;a[v]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans+1<<endl;

	return 0;
}
