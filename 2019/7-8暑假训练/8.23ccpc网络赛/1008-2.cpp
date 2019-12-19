#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n;ll k;ll a[N];

priority_queue <int,vector<int>,less<int> > kaoyu;
priority_queue <int,vector<int>,greater<int> > buyu;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		
		ll ans=0;int pt=0;
		while(pt<n){
			if(kaoyu.empty()){
				if(!buyu.empty()){
					ans+=buyu.top();buyu.pop();
				}
				else ans+=k;
				kaoyu.push(a[++pt]);
			}
			int temp = kaoyu.top();kaoyu.pop();ans+=temp;
			int ca = temp/k;
			for(int i=1;i<=ca&&pt<n;i++){
				kaoyu.push(a[++pt]);
			}
			if(temp%k!=0){
				buyu.push(k-temp%k);
			}
		}
		while(!kaoyu.empty()){
			ans+=kaoyu.top();kaoyu.pop();
		}
		while(!buyu.empty()){
			buyu.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
