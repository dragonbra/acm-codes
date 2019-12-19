#include <bits/stdc++.h>
using namespace std;

int a[3000010];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);double ans;
	if(n%2==0) ans=(a[n/2]+a[(n+2)/2])/2.0;
	else ans=a[(n+1)/2]*1.0;
	printf("%.1lf\n",ans);
}
