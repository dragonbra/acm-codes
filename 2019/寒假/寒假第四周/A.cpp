#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long a,b,c,d,sum;int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		sum=a+b+c+d;
		if(sum==0&&a!=0)
 		    cout<<"18446744073709551616"<<endl;
		else 
	        cout<<sum<<endl;
	}
}
