#include <bits/stdc++.h>
using namespace std;
int T,N;
int a[53]={0};
int ans=0;

int qp(int x,int t){
	int res = 1;
	while(t){
		if(t&1) res*=x;
		x*=x;
		t>>=1;
	}
	return res;
}

int main(){
	scanf("%d %d",&T,&N);
	
	for(int i=1;i<=N;i++){
		int cnt;scanf("%d",&cnt);
		while(cnt--){
			int t;scanf("%d",&t);
			a[i]+=qp(2,t-1);
		}
	}
	
	//for(int i=1;i<=N;i++) cout<<a[i]<<endl;
	int cmp = qp(2,T);
	for(int i=1;i<=cmp;i++){
		bool flag=true;
		for(int j=1;j<=N;j++){
			if((i&a[j])==a[j]){
				flag=false;break;
			}
		}
		if(flag) ans++;
	}
	
	printf("%d\n",ans);
	
	return 0;
}
