#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4000; 

ll a[N];bool vis[N+10];
ll cnt=0;ll n;

void init(){
	for(int i=2;i<=N;i++){
		if(!vis[i]){
			a[++cnt]=i;
			for(int j=i*2;j<=N;j+=i){
				vis[j]=1;
			}
		}
	}
}

ll powp(ll x,ll p){
	ll res=1;
	while(p--){
		res*=x;
	}
	return res;
}

bool check(ll num,ll p){
	ll l=2,r=1000000000;
	if(p==3) r=1000000;
	else if(p==4) r=40000;
	while(l<=r){
		ll mid=(l+r)/2;
		ll midpow=powp(mid,p);
		if(midpow==num) return true;
		else if(midpow<num) l=mid+1;
		else r=mid-1;
	}
	return false;
}

int ef()
{
    ll l = 4001,r = 1e9;
    while(l<=r){
        ll mid=l+r>>1;
        ll tp=mid*mid;
        if(tp==n) return 2;
        else if(tp>n) r=mid-1;
        else l=mid+1;
    }
    l=4001,r=1e6;
    while(l<=r){
        ll mid=l+r>>1;
        ll tp=mid*mid*mid;
        if(tp==n) return 3;
        else if(tp>n) r=mid-1;
        else l=mid+1;
    }
    l=4001,r=1e5;
    while(l<=r){
        ll mid=l+r>>1;
        ll tp=mid*mid*mid*mid;
        if(tp==n) return 4;
        else if(tp>n) r=mid-1;
        else l=mid+1;
    }
    return 1;
}

int main(){
	init();
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		int ans=100;
		for(int i=1;i<=cnt;i++){
			int p=0;
			while(n%a[i]==0){
				n/=a[i];
				p++;
			}
			if(p) ans=min(ans,p);
		}
		if(n==1||ans==1) ;
		else ans=min(ans,ef());
		printf("%d\n",ans);
		//cout<<powp(2,3);
	}
	return 0;
}
