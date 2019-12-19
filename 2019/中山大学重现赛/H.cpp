#include <bits/stdc++.h>
using namespace std;

int x,y,z;int ans;
bool xoy[110][110];bool yoz[110][110];bool zox[110][110];
int xv[110],yv[110];//x~i,y~j; xoy[i][j]
struct 

void init(){
	ans=0;
	memset(xoy,0,sizeof(xoy));
	memset(yoz,0,sizeof(yoz));
	memset(zox,0,sizeof(zox));
	memset(xv,0,sizeof(xv));
	memset(yv,0,sizeof(yv));
}

void scan(){
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++) scanf("%d",&xoy[i][j]);
	
	for(int i=1;i<=y;i++)
		for(int j=1;j<=z;j++) scanf("%d",&yoz[i][j]);
		
	for(int i=1;i<=y;i++){
		for(int j=1;j<=z;j++){
			if(yoz[i][j]) yv[i]++;
		}
	}
		
	for(int i=1;i<=z;i++)
		for(int j=1;j<=x;j++) scanf("%d",&zox[i][j]);
		
	for(int i=i;i<=x;i++)
		for(int j=1;j<=z;j++){
			if(zox[j][i]) xv[i]++;
		}
}

void accumu(){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(xoy[i][j]){
				if(xv[i]==0&&yv[j]==0) ans+=1;
				else if(xv[i]==0){
					ans+=yv[j];yv[j]=0;
				}
				else if(yv[j]==0){
					ans+=xv[i];xv[i]=0;
				}
				else{//both not 0
					if(xv[i]>yv[j]){
						ans+=yv[j];yv[j]=0;
					}
					else if(xv[i]<yv[j]){
						ans+=xv[i];xv[i]=0;
					}
					else{//equal
						ans+=xv[i];xv[i]=yv[j]=0;
					}
				}
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
	
	for(int i=1;i<=y;i++) cout<<yv[i]<<' ';
	cout<<endl;
	for(int i=1;i<=x;i++) cout<<xv[i]<<' ';
	cout<<endl;cout<<endl;
}

int main(){
	while(scanf("%d %d %d",&x,&y,&z)!=EOF){
		init();
		scan();
		check();
		accumu();
		printf("%d\n",ans);
	}
	return 0;
}
