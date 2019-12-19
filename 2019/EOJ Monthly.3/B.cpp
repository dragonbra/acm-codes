#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n;int cnt=0;
	while(l<r){
		if(a[l]==a[r]){
			l++;r--;continue;
		}
		else if(a[l]<a[r]){
			a[l+1]+=a[l];l++;cnt++;continue;
		}
		else{
			a[r-1]+=a[r];r--;cnt++;continue;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
