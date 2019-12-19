#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n;ll k;ll a[N];

bool cmp(ll a,ll b){
	return a>b;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1,cmp);
		
		ll ans=0;ans+=k;int head=1,pt=1,cnt=1;
		while(head<n){
			ans+=max(a[pt],k);head++;
			if(a[pt]>k){
				//if(a[head]-k>k) 
				int cmp=(a[pt]/k-1);
				if(head+cmp>=n){
					cmp=n-head;
					head=n;cnt=n-pt;
					break;
				}
				else{
					head+=cmp;
					cnt+=cmp;
					a[pt]-=(a[pt]/k*k);
				}
				
				if( a[pt] >= k-a[pt] + a[n-cnt+1] ){
					ans+=k-a[pt];head++;cnt++;
				}
				pt++;
			}
		}
		for(int i=1;i<=cnt;i++){
			ans+=a[n-i+1];
		}
		printf("%lld\n",ans);
		
		
	}
	return 0;
}

