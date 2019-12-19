#include <bits/stdc++.h>
using namespace std;
int n,m,k;

int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		int a[10010]={0};int c[1010]={0};int cc[1010]={0};
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];c[a[i]]++;
		}
		for(int i=1;i<=n/2;i++){
			cc[a[i]]++;
		}
		int ans = 0;
		for(int i=1;i<=m;i++){
			int t = c[i]/k;
			ans += min(t,cc[i]); 
		}
		cout<<ans<<endl;
	}
	return 0;
}
