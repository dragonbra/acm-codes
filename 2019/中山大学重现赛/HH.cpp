#include <bits/stdc++.h>
using namespace std;

int x,y,z;int ans;
bool xoy[110][110];bool yoz[110][110];bool zox[110][110];

void init(){
	ans=0;
	memset(xoy,0,sizeof(xoy));
	memset(yoz,0,sizeof(yoz));
	memset(zox,0,sizeof(zox));
}

void scan(){
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++) scanf("%d",&xoy[i][j]);
	
	for(int i=1;i<=y;i++)
		for(int j=1;j<=z;j++) scanf("%d",&yoz[i][j]);
		
	for(int i=1;i<=z;i++)
		for(int j=1;j<=x;j++) scanf("%d",&zox[i][j]);
}

void accumu(){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			for(int k=1;k<=z;k++){
				if(xoy[i][j]&&yoz[j][k]&&zox[k][i]) ans++;
			}
		}
	}
}

void check(){
	cout<<endl;
	
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++) cout<<xoy[i][j]<<' ';
		cout<<endl;
	}
}

int main(){
	while(scanf("%d %d %d",&x,&y,&z)!=EOF){
		init();
		scan();
		//check();
		accumu();
		printf("%d\n",ans);
	}
	return 0;
}
