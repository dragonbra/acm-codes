#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];

int gcd(int a,int b){
	if(a>b) swap(a,b);
	return a==0?b:gcd(b-a,a);
}

inline int read(){
	int x=0,f=1;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		x*=10;x=x+t-'0';
		t=getchar();
	}
	return x*f;
}

int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) a[i]=read();
	
	sort(a+1,a+n+1);
	
	int res=a[1],ans=1;int cmp=2;for(int i=2;i<=n;i++){
		a[i]/=gcd(a[i],res);
	}
	sort(a+2,a+n+1);
	while(res*a[cmp]<=k&&cmp<=n){
		res=res*a[cmp];ans++;cmp++;
		for(int i=cmp;i<=n;i++){
			a[i]/=gcd(a[i],res);
		}
		sort(a+cmp,a+n+1);
	}
	if(res>k) cout<<"0 "<<k<<endl;
	else cout<<ans<<' '<<k/res<<endl;
}
