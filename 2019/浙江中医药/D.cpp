#include <iostream>
using namespace std;

int main(){
	long long n,l,mk=0,t;
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		mk = t > mk ? t : mk;
	}
	if(mk<l) cout<<"0"<<endl;
	else cout<<mk-l<<endl;
}
