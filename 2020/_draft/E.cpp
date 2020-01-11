#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

char mapp[1010][1010];
int tran[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int m;

void dfs(int a,int b) {
    mapp[a][b]='.';
    for(int i=0;i<4;i++){
        int nx = a + tran[i][0], ny = b + tran[i][1];
        if ( 0<=nx && nx<m && 0<=ny && ny<m && mapp[nx][ny]=='*' ) dfs(nx,ny);
    }
    return;
}

int main() {
    scanf("%d",&m);
    int res=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>mapp[i][j];
         
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            if(mapp[i][j]=='*'){
                dfs(i,j);
                res++;
            }
        }
    printf("%d\n",res);
}
//author:caramel_pudding