#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool car[1025][1025];

int pow_(int x,int m){
	int res=1;
	while(m--) res*=x;
	return res;
}

int main(){
	int T;scanf("%d",&T);
	car[1][1]=car[1][2]=car[2][2]=0,car[2][1]=1;//0=C,1=P
	for(int k=1;k<=9;k++){
		int cmp=pow_(2,k);
		for(int i=1;i<=cmp;i++){
			for(int j=1;j<=cmp;j++){
				car[i][j+cmp]=car[i+cmp][j+cmp]=car[i][j];
				car[i+cmp][j]=!car[i][j];
			}
		}
	}
	while(T--){
		int k;scanf("%d",&k);int num = pow_(2,k);
		for(int i=1;i<=num;i++){
			for(int j=1;j<=num;j++){
				if(car[i][j]) printf("P");
				else printf("C");
			}
			printf("\n");
		}
	}
	return 0;
}

