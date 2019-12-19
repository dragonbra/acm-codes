#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e6 + 10 ;
int n,ch[maxn][30],val[maxn],cnt,m;
int f[maxn][31],Dep[maxn];
string str[100010];
void dfs(int u,int fa)
{
    Dep[u]=Dep[fa]+1;
    for(int i=0;i<=29;i++) f[u][i+1]=f[f[u][i]][i];
    for(int i=0;i<=26;i++)
    {
        int v = ch[u][i];
        if(!v) continue;
        f[v][0]=u;
        dfs(v,u);
    }
}
void insert(int pos)
{
    int len = str[pos].length(),u=0;
    for(int i=0;i<len;i++)
    {
        int x = str[pos][i]-'a';
        if(!ch[u][x]) ch[u][x]=++cnt;
        u=ch[u][x];
    }
    val[pos]=u;
}
int LCA(int x,int y)
{
    if(Dep[x]<Dep[y]) swap(x,y);
    for(int i=30;i>=0;i--)
    {
        if(Dep[f[x][i]]>=Dep[y]) x=f[x][i];
        if(x==y) return x;
    }
    for(int i=30;i>=0;i--)
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    return f[x][0];
}
int main()
{
	//freopen("H.txt","r",stdin);
    int T;scanf("%d",&T);int TT=T;
    while(T--){
    	printf("Case %d:\n",TT-T);
    	
    	cnt=0;
    	memset(f,0,sizeof(f));
    	memset(val,0,sizeof(val));
    	memset(ch,0,sizeof(ch));
    	memset(Dep,0,sizeof(Dep));
    	cin>>n;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>str[i];
	        insert(i);
	    }
	    dfs(0,-1);
	    cin>>m;
	    for(int i=1,a,b;i<=m;i++)
	    {
	        scanf("%d%d",&a,&b);
	        int lca=LCA(val[a],val[b]);
	        printf("%d\n",Dep[lca]-1);
	    }
	}
    return 0;
}
