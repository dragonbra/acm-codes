#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,ans;
	int n;long long cmp=pow(2,61);//cout<<cmp;2305843009213693952
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c>>d;
		if(a==cmp&&b==cmp&&c==cmp&&d==cmp){
			cout<<"9223372036854775808"<<endl;
		}
		else{
		ans=a+b+c+d;
		cout<<ans<<endl;
		}
	} 
	return 0;
}
