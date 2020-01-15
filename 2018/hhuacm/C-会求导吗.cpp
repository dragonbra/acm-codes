#include <iostream>
using namespace std;

int main(){
	int n,ans=0,t=1;
	cin>>n;
	while(n){
		t*=n;ans+=t;n--;
	}
	cout<<ans<<endl;
}
