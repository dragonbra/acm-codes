#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N],b[N];
int aa[N],bb[N];
int n;

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		
		aa[1]=a[1]; bb[1]=b[1]; int ans=1;
		
		for(int i=2;i<=n;i++){
			if(a[i]<a[i-1]&&b[i]<b[i-1]){
				int acnt=1;
				while(a[i]>aa[acnt]&&acnt<i){
					acnt++;
				}
				aa[i]=a[i];sort(aa+1,aa+i+1);
				
				int bcnt=1;
				while(b[i]>bb[bcnt]&&bcnt<i){
					bcnt++;
				}
				bb[i]=b[i];sort(bb+1,bb+i+1);
				
				if(acnt==bcnt){
					//cout<<acnt<<' '<<bcnt<<endl;
					ans++;
				}
				else{
					break;
				}
			}
			else if(a[i]>a[i-1]&&b[i]>b[i-1]){
				aa[i]=a[i];sort(aa+1,aa+i+1);
				bb[i]=b[i];sort(bb+1,bb+i+1);
				ans++;
			}
			else{
				break;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
