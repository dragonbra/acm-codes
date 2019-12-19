#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[7];
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int mk=0,sum=0;
		for(int j=1;j<=6;j++){
			scanf("%d",&a[j]);
			sum += a[j];
		}
		for(int j=1;j<=6;j++){
			if(a[mk]<=a[j]) mk=j;
		}
		double ans = 1.0*a[mk]/sum*mk;
		printf("%.12lf\n",ans);
	}
	return 0;
}
