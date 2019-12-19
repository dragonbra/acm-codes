#include <bits/stdc++.h>
using namespace std;
int mp[101][101];int s[101][101];
bool vis[101][101];int ts[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n,m,x,y;

struct node{
	int x,y,s;
};

bool check(int x,int y){
	if(x<1||y<1||x>n||y>m||vis[x][y]||mp[x][y]) return false;
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

int main(){
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	bfs(1,1);
	cout<<s[x][y];
	return 0;
}
