#include <bits/stdc++.h>
using namespace std;

bool is2(int x){
	bool flag=1;
	while(x>1){
		if(x%2==1){
			flag=0;break;
		}
		x/=2;
	}
	return flag;
}

int bigf(int x){
	int res=2;
	if(x%2==1){
		while(res<x){
			if(x%res==1) res*=2;
			else break;
		}
		if(res>x||x%res!=1) res/=2;
		return res;
	}
	else{
		while(res<x){
			if(x%res==0) res*=2;
			else break;
		}
		if(res>x||x%res!=0) res/=2;
		return res;
	}
}

int main(){
	int T;cin>>T;
	while(T--){
		//cout<<bigf(66)<<endl;
		int a,b;int ans;
		scanf("%d %d",&a,&b);
		if(a==b||a==1) ans=b;
		else if(a%2==1){
			if(b%2==0){
				if(a+min(bigf(a),bigf(b))-1==b){
					ans=b;
				}
				else ans=-1;
			}
			else if(b%2==1){
				//cout<<bigf(a)<<endl;
				if(a+bigf(a)-1>=b) ans=b;
				else ans=-1;
			}
		}
		else if(a%2==0){
			if(b%2==0) ans=-1;
			else if(b%2==1) ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
