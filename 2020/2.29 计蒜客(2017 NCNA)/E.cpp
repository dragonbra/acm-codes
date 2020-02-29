#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
string a,b,c;
map<string,int>mmap;
int n,m,T;
int is[510][510],has[510][510];
int main(){
//	freopen("1.txt","w",stdout);
	scanf("%d%d",&m,&T);
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(!mmap.count(a))mmap[a]=++n;
		if(!mmap.count(c))mmap[c]=++n;
		if(b[0]=='i')is[mmap[a]][mmap[c]]=1;
		else has[mmap[a]][mmap[c]]=1;
	}
	for(int i=1;i<=n;i++)is[i][i]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				is[i][j]=is[i][j]||(is[i][k] && is[k][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				has[i][j]=has[i][j]||(has[i][k] && has[k][j]);
				has[i][j]=has[i][j]||(is[i][k] && has[k][j]);
				has[i][j]=has[i][j]||(has[i][k] && is[k][j]);
			}
	for(int ttt=1;ttt<=T;ttt++){
		cin>>a>>b>>c;
		printf("Query %d: ",ttt);
		if(!mmap.count(a))mmap[a]=++n;
		if(!mmap.count(c))mmap[c]=++n;
		if(b[0]=='i'){
			if(is[mmap[a]][mmap[c]])puts("true");
			else puts("false");
		}else{
			if(has[mmap[a]][mmap[c]])puts("true");
			else puts("false");
		}
	}
	return 0;
}
