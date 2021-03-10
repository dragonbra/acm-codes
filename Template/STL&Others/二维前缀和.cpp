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
int main(){
	scanf("%d%lld",&n,&s);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	printf("%lld\n",f[n][n]+f[0][0]-f[0][n]-f[n][0]);
	/*
		二维前缀和
		f[x][y]+f[i][j]-f[i][y]-f[x][j]
		表示矩形(i,j)-(x,y)的面积 
	*/ 
	return 0;
}
