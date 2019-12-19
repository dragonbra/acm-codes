#include <iostream>
using namespace std;
int a[110];
int b[1100010];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[1]=1;
	int i=1,ans=0,cnt=0;
	while(1){
		if(b[i]>n){
			cnt=i;break;
		}
		
		b[i*2]=b[i]+5; b[i*2+1]=a[b[i]];
		
		cnt++;i++;
	}
	
	while(cnt>0){
		ans++;cnt/=2;
	}
	ans--;
	cout<<ans*2<<endl;
}
