#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;int n,m,k,a,b,c;
	while(T--){
		cin>>n>>m>>k>>a>>b>>c;
		long long a6 = min(min(3*a,2*b),2*a+b);
		long long a1 = min(a,b), a2 = min(a,b), a3 = min(2*a,b), 
  			 	  a4 = min(2*a,min(a+b,2*b)), a5 = min(min(a+b,3*a),2*b);
		long long rans = 1e15;
		for(int i=0;i<=k;i++){//i¸öÇéÂÂ¼ä 
			long long ans = 0;
			ans += i * c;
			long long nan = n + (k-i);
			long long nv = m + (k-i);
			ans += (nan/6 + nv/6) * a6;
			nan%=6;nv%=6;
			
			if(nan==1) ans+=a1;
			else if(nan==2) ans+=a2;
			else if(nan==3) ans+=a3;
			else if(nan==4) ans+=a4;
			else if(nan==5) ans+=a5;
			
			if(nv==1) ans+=a1;
			else if(nv==2) ans+=a2;
			else if(nv==3) ans+=a3;
			else if(nv==4) ans+=a4;
			else if(nv==5) ans+=a5;
			
			rans = min(ans,rans);
		}
		cout<<rans<<endl;
	}
	return 0;
}
