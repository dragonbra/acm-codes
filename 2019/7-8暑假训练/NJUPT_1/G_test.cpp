#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
int gcd(int a,int b){return a==0 ? b:gcd(b%a,a);} 

int main(){
	freopen("ans.txt","w",stdout);
	for(int i=2;i<=N;i++){
		int cnt=0;
		for(int j=1;j<=i;j++){
			if(gcd(j,i-j)==1) cnt++;
		}
		cout<<cnt<<',';
	}
	
	return 0;
}
