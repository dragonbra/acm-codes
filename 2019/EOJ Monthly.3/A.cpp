#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int a=2,b=n*2+1,c=n*3+1;
	for(int i=1;i<=n;i++){
		printf("%d %d %d\n",a,b,c);
		a++;b--;c++;
		if(a*a + b*b >= c*c || a+b<=c){
			cout<<"NO!"<<endl;
			break;
		}
	}
	return 0;
}
