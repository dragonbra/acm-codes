#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a[7];
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long mk=0,sum=0;
		for(int j=1;j<=6;j++){
			scanf("%lld",&a[j]);
			if(a[j]*j>mk) mk = a[j]*j;
			sum += a[j];
		}
		double ans = 1.0*mk/sum;
		printf("%.12lf\n",ans);
	}
	return 0;
}
