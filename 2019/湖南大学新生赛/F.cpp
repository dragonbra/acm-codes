#include <bits/stdc++.h>
using namespace std;
int digit[21];int n;
long long lft[21];
long long rt[21];

int merge(int n){
	int mer = digit[n]*100+digit[n+1]*10+digit[n+2];
	return mer;
}

int main(){
	cin>>n;long long temp;long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>temp;long long mk = temp , res = 10; int ai=0;int di;int num;
		while(mk>0){
			ai++;mk/=10;
		}
		mk=temp;di=ai;num=ai;
		while(mk>0){
			digit[ai]=mk%10;
			mk/=10;ai--;
		}
		mk=temp;ai=num;
		while(mk>0){
			lft[ai]=mk+1;
			mk/=10;ai--;
		}
		mk=temp;
		while(di>0){
			rt[di]=mk%res+1;
			res*=10;di--;
		}
		lft[0]=1;rt[num+1]=1;
		
		/*
		for(int j=1;j<=num;j++){
			cout<<lft[j]<<endl;
		}
		for(int j=1;j<=num;j++){
			cout<<rt[j]<<endl;
		}
		*/
		long long dd[21];
		dd[num]=10;ai=num-1;
		while(ai>0){
			dd[ai]=dd[ai+1]*10;ai--;
		}
		
		
		for(int i=1;i<=num-2;i++){
			//cout<<merge(i)<<endl;
			if(merge(i)>520) ans+=(lft[i-1]*dd[i+3]);
			else if(merge(i)==520) ans+=(lft[i-1]*rt[i+3]);
			else ans+=((lft[i-1]-1)*dd[i+3]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
