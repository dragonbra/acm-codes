#include <bits/stdc++.h>
using namespace std;
long long sum[100010];
long long aa[100010]; 
int n,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	long long ans = 0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	sort(aa+1,aa+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+aa[i];
	}
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		long long cmp = sum[b]-sum[a-1];
		ans = cmp > ans ? cmp : ans;
	}
	cout<<ans<<endl;
	return 0;
}
