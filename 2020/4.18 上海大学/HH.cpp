#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[100005];
int a[15];

struct node{
	int a[10];
	bool f;
	bool operator<(const node&u)const{
		for(int i=9;i>=0;i--) {
			if(a[i]!=u.a[i])return a[i]<u.a[i];
		}
		return a[9]<u.a[9];
	}
} dp[100005][3],t;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

bool f0(){
	if(t.a[9]<a[9]){
		t.a[9]++;
		return 1;
	}
	if(t.a[6]<a[6]){
		t.a[6]++;
		return 1;
	}
	if(t.a[3]<a[3]){
		t.a[3]++;
		return 1;
	}
	if(t.a[0]<a[0]){
		t.a[0]++;
		return 1;
	}
	return 0;
}

bool f1(){
	if(t.a[7]<a[7]){
		t.a[7]++;
		return 1;
	}
	if(t.a[4]<a[4]){
		t.a[4]++;
		return 1;
	}
	if(t.a[1]<a[1]){
		t.a[1]++;
		return 1;
	}
	return 0;
}

bool f2(){
	if(t.a[8]<a[8]){
		t.a[8]++;
		return 1;
	}
	if(t.a[5]<a[5]){
		t.a[5]++;
		return 1;
	}
	if(t.a[2]<a[2]){
		t.a[2]++;
		return 1;
	}
	return 0;
}

int main(){
	redirect();
	int T,k;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%s%d",s,&k);
		for(int i=0;i<=k;i++){
			for(int j=0;j<3;j++){
				dp[i][j].f=0;
				for(int k=0;k<10;k++) dp[i][j].a[k]=0;
			}
		}

		for(int i=0;i<strlen(s);i++) a[s[i]-'0']++;
		dp[0][0].f=1;
		for(int i=1;i<=k;i++){
			if(dp[i-1][0].f){
				t=dp[i-1][0];
				if(f0()){
					dp[i][0]=max(dp[i][0],t);
					dp[i][0].f=1;
				}
				t=dp[i-1][0];
				if(f1()){
					dp[i][1]=max(dp[i][1],t);
					dp[i][1].f=1;
				}
				t=dp[i-1][0];
				if(f2()){
					dp[i][2]=max(dp[i][2],t);
					dp[i][2].f=1;
				}
			}
			
			if(dp[i-1][1].f){
				t=dp[i-1][1];
				if(f0()){
					dp[i][1]=max(dp[i][1],t);
					dp[i][1].f=1;
				}
				t=dp[i-1][1];
				if(f1()){
					dp[i][2]=max(dp[i][2],t);
					dp[i][2].f=1;
				}
				t=dp[i-1][1];
				if(f2()){
					dp[i][0]=max(dp[i][0],t);
					dp[i][0].f=1;
				}
			}
			
			if(dp[i-1][2].f){
				t=dp[i-1][2];
				if(f0()){
					dp[i][2]=max(dp[i][2],t);
					dp[i][2].f=1;
				}
				t=dp[i-1][2];
				if(f1()){
					dp[i][0]=max(dp[i][0],t);
					dp[i][0].f=1;
				}
				t=dp[i-1][2];
				if(f2()){
					dp[i][1]=max(dp[i][1],t);
					dp[i][1].f=1;
				}
			}
		}
		
		if(!dp[k][0].f)puts("-1");
		else{
			int sum=0;
			for(int i=9;i>=0;i--)sum+=i*dp[k][0].a[i];
			if(!sum){
				if(k==1)puts("0");
				else puts("-1");
			}
			else{
				for(int i=9;i>=0;i--)
				for(int j=1;j<=dp[k][0].a[i];j++)printf("%d",i);
				puts("");
			}
		}
	}
	return 0;
}
