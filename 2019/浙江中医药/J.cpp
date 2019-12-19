#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int mod = 100000007;
int a[10010],sum[3];
int main(){
	memset(a,0,sizeof(a));memset(sum,0,sizeof(sum));
	a[0]=1;sum[2]=1;
	for(int i=1;i<=10000;i++){
		a[i]+=a[i-1];a[i]%=mod;
		if(i%2==1){
			a[i]+=sum[1];a[i]%=mod;
			sum[1]+=a[i];sum[1]%=mod;
		}
		else{
			a[i]+=sum[2];a[i]%=mod;
			sum[2]+=a[i];sum[2]%=mod;
		}
	}
	//for(int i=1;i<=100;i++) cout<<a[i]<<endl;
	
	
	int t;
	while(scanf("%d",&t)!=EOF){
		printf("%d\n",a[t]);
	}
}
