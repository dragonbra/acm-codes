#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

bool a[20][20];int ans=10000000;

void change(int x,int y){
	a[x][y]=!a[x][y];
	if(x>1) a[x-1][y]=!a[x-1][y];
	if(x<4) a[x+1][y]=!a[x+1][y];
	if(y>1) a[x][y-1]=!a[x][y-1];
	if(y<4) a[x][y+1]=!a[x][y+1];
}

bool is_over(){
	bool f=1;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]!=a[1][1]) f=0;
		}
	}
	return f;
}

void dfs(int x,int y,int s){
    if(is_over()){
    	ans=min(ans,s);return;
	}
	if(x>4||y>4) return;
    
	if(y==4) dfs(x+1,1,s);
	else dfs(x,y+1,s);
    
    change(x,y);

	if(y==4) dfs(x+1,1,s+1);
	else dfs(x,y+1,s+1);
	
    change(x,y);
}

int main(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			char t;cin>>t;
			if(t=='b') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	
	dfs(1,1,0);
	if(ans==10000000) printf("Impossible\n");
	else printf("%d\n",ans);
	return 0;
}

