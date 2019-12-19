#include <bits/stdc++.h>
using namespace std;
const int maxn = 710;
int m[maxn][maxn],s[maxn][maxn];
bool vis[maxn][maxn];
int n,ans;int sx,sy,ex,ey;

int ts[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int ts2[8][2]={ {0,1},
				{1,1},
				{1,0},
				{1,-1},
				{0,-1},
				{-1,-1},
				{-1,0},
				{-1,1}};

struct node{
	int x,y,s;
};

void init(){
	memset(vis,0,sizeof(vis));
	memset(s,0,sizeof(s));
	memset(m,0,sizeof(m));
	ans=maxn*maxn;//Ô­À´ÊÇ3*maxn 
	sx=sy=ex=ey=0;
}

bool check(int x,int y){
	if(x<1||y<1||x>n||y>n||vis[x][y]||m[x][y]) return false;
	else return true;
}

bool check2(int x,int y){
	if(x<1||y<1||x>n||y>n||m[x][y]) return false;
	else return true;
}

void bfs(int x,int y){
	queue<node> Q;
	node a,next;
	a.x=x,a.y=y,a.s=0;vis[x][y]=1;
	
	Q.push(a);
	
	while(!Q.empty()){
		
		a=Q.front();s[a.x][a.y]=a.s;
		Q.pop();
		
		for(int i=0;i<4;i++){
			next = a; next.x+=ts[i][0]; next.y+=ts[i][1]; next.s+=1;
			if(check(next.x,next.y)){
				vis[next.x][next.y]=1;
				Q.push(next);
			}
		}
		
	}
}

void output(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(2)<<s[i][j]<<' ';
		}
		cout<<endl;
	}
}

void span(int x,int y){
	for(int i=0;i<8;i++){
		int tx=x,ty=y;
		while(check2(tx,ty)){
			//s[tx][ty]=-1;
			if(vis[tx][ty]) ans = min(ans, s[tx][ty]);
			tx+=ts2[i][0];
			ty+=ts2[i][1];
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(scanf("%d",&n)!=EOF){
		init();
		//scan
		for(int i=1;i<=n;i++){
			char ls[maxn];
			scanf("%s",ls);
			for(int j=1;j<=n;j++){
				if(ls[j-1]=='S') sx=i,sy=j,m[i][j]=0;
				else if(ls[j-1]=='M') ex=i,ey=j,m[i][j]=0;
				else if(ls[j-1]=='#') m[i][j]=1;
				else if(ls[j-1]=='.') m[i][j]=0;
			} 
		}
		
		//bfs
		bfs(sx,sy);
		
		//return ans
		span(ex,ey);
		
		//output
		//output();
		
		//output ans
		if(ans==maxn*maxn) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}
