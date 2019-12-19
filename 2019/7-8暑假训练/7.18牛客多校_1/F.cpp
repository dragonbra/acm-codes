#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL S,E;
LL x1,x2,x3,y11,y2,y3;

int main(){
	while(~scanf("%lld %lld %lld %lld %lld %lld",&x1,&y11,&x2,&y2,&x3,&y3)){
		S = ( (x1*y2-x2*y11) - (x1*y3-x3*y11) + (x2*y3-x3*y2) )/2;
		if(S<0) S=-S; 
		E = S*28;
		printf("%lld\n",E);
	}
	return 0;
}
