#include <bits/stdc++.h>
using namespace std;
int n,m;int cnt;int ex,ey,sx,sy;
int mp[2010][2010],s[2010][2010],s2[2010][2010];//'1'means stone,0 means road;
bool vis[2010][2010],vis2[2010][2010];

int ts[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct node{
	int x,y,s;
} ys[100010];

void init(){
	cnt=0;
	memset(mp,0,sizeof(mp));
	memset(s,0,sizeof(s));
	memset(s2,0,sizeof(s2));
	memset(ys,0,sizeof(ys));
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
}

bool check(int x,int y){
    if(x<1||y<1||x>n||y>m||vis[x][y]||mp[x][y]) return false;
    else return true;
}

bool check2(int x,int y){
    if(x<1||y<1||x>n||y>m||vis2[x][y]||mp[x][y]) return false;
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
void bfs2(int x,int y){
    queue<node> Q;
    node a,next;
    a.x=x,a.y=y,a.s=0;vis2[x][y]=1;
     
    Q.push(a);
     
    while(!Q.empty()){
         
        a=Q.front();s2[a.x][a.y]=a.s;
        Q.pop();
         
        for(int i=0;i<4;i++){
            next = a; next.x+=ts[i][0]; next.y+=ts[i][1]; next.s+=1;
            if(check2(next.x,next.y)){
                vis2[next.x][next.y]=1;
                Q.push(next);
            }
        }
         
    }
}

int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		init();
		
		char h[3010];
		for(int i=1;i<=n;i++){
			scanf("%s",h);
			for(int j=1;j<=m;j++){
				if(h[j-1]=='W'){
					ys[cnt+1].x=i;ys[cnt+1].y=j;
					cnt++;
					mp[i][j]=0;
				}
				else if(h[j-1]=='.'){
					mp[i][j]=0;
				}
				else if(h[j-1]=='#'){
					mp[i][j]=1;
				}
				else if(h[j-1]=='L'){
					sx=i,sy=j;
					mp[i][j]=0;
				}
				else if(h[j-1]=='Q'){
					ex=i,ey=j;
					mp[i][j]=0;
				}
			} 
		}
		
		bfs(sx,sy);
		bfs2(ex,ey);
		
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout<<setw(2)<<s2[i][j]<<' ';
			cout<<endl;
		}
		*/
		
		int mk=1e9;
		for(int i=1;i<=cnt;i++){
			int xx=ys[i].x,yy=ys[i].y;
			if(s[xx][yy]!=0&&s2[xx][yy]!=0){
				if(s[xx][yy]+s2[xx][yy]<=mk) mk=s[xx][yy]+s2[xx][yy];
			}
		}
		
		cout<<mk<<endl;
	}
}
