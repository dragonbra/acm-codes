#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e3+10;
int T;
ll k,m;

ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&k,&m);
		ll ans = 1e18+10;
		bool flag=false;
		for(ll i=m;i<=N;i++){
			ll tn=k^i;
			if(gcd(tn+i,tn)!=1||tn<=0) continue;
			
			int cnt=0;
			for(ll j=1;j<=i;j++){
				if(gcd(tn+j,tn)==1){
					cnt++;
					if(cnt==m&&j==i){
						flag=true;
						if(tn<ans) ans=tn;
						break;
					}
				}
			}
		}
		if(!flag) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}

