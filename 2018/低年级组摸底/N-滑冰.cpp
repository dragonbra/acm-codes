#include <bits/stdc++.h>
using namespace std;

int aa[11][11];
bool mk[11][11];bool aaa[11][11];
struct point{
	int x,y;
} p[110];


int head=1,tail=2;int n,m;

void bfs(point a){
	int i=a.x,j=a.y;mk[i][j]=1;aaa[i][j]=1;
	//cout<<i<<' '<<j<<"//";
	//x-1 
	while(i-1>=1&&aa[i-1][j]!=1){
		i--;mk[i][j]=1;
	}
	if(aa[i-1][j]==1&&i!=a.x&&aaa[i][j]!=1){
		p[tail].x=i;p[tail].y=j;
		tail++;
	}
	
	i=a.x,j=a.y;
	//x+1
	while(i+1<=n&&aa[i+1][j]!=1){
		i++;mk[i][j]=1;
	}
	if(aa[i+1][j]==1&&i!=a.x&&aaa[i][j]!=1){
		p[tail].x=i;p[tail].y=j;
		tail++;
	}
	
	i=a.x,j=a.y;
	//y-1
	while(j-1>=1&&aa[i][j-1]!=1){
		j--;mk[i][j]=1;
	}
	if(aa[i][j-1]==1&&j!=a.y&&aaa[i][j]!=1){
		p[tail].x=i;p[tail].y=j;
		tail++;
	}
	
	i=a.x,j=a.y;
	//y+1
	while(j+1<=m&&aa[i][j+1]!=1){
		j++;mk[i][j]=1;
	}
	if(aa[i][j+1]==1&&j!=a.y&&aaa[i][j]!=1){
		p[tail].x=i;p[tail].y=j;
		tail++;
	}
	
	
	head++;
}

void out(){
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<mk[i][j];
		cout<<endl;
	}
}

int main(){
	
	memset(aa,0,sizeof(aa));
	memset(aaa,0,sizeof(aaa));
	memset(mk,0,sizeof(mk));
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		char t[11];scanf("%s",t); 
			for(int j=1;j<=m;j++){
				if(t[j-1]=='K') p[1].x=i,p[1].y=j;
				else if(t[j-1]=='X') aa[i][j]=1;
				else if(t[j-1]=='U') aa[i][j]=2;
			}
	}
	//out();
	
	while(head<tail)	bfs(p[head]);
	
	bool ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(aa[i][j]==2&&mk[i][j]==1) ans=1;
		}
	}
	//out();
	if(ans) cout<<"Dangerous"<<endl;
	else cout<<"Safe"<<endl;
	
	
} 
