#include <bits/stdc++.h>
using namespace std;
unsigned int a[5000010];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		bool flag = false;
		
		if(n<3) flag = false;
		else if(n>100) flag = true;
		else{
			sort(a+1,a+n+1);
			for(int i=1;i<=n-2;i++){
				if(a[i]+a[i+1]>a[i+2]){
					flag=true;break;
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
