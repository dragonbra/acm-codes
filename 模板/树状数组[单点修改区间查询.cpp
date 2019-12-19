#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
char s[maxn];
int f[30][maxn];
int tree[30][maxn],len;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int lowbit(int k){return k&-k;}
void add(int j,int x,int k){
	while(x<=len){
		tree[j][x]+=k;
		x+=lowbit(x);
	}
}
int sum(int j,int x){
	int res=0;
	while(x!=0){
		res+=tree[j][x];
		x-=lowbit(x);
	}
	return res;
}
int main(){
	scanf("%s",&s);
	len=strlen(s);
	for(int i=0;i<len;i++)
		for(int j='a'-'a';j<='z'-'a';j++)if(j==s[i]-'a')f[j][i+1]=1;
	for(int j=0;j<='z'-'a';j++)
		for(int i=1;i<=len;i++)add(j,i,f[j][i]);
	int T;
	scanf("%d",&T);
	while(T--){
		int opt;
		scanf("%d",&opt);
		if(opt==2){
			int l,r,ans=0;
			scanf("%d%d",&l,&r);
			for(int i=0;i<26;i++)
				if(sum(i,r)-sum(i,l-1)==0)continue;
				else ans++;
			printf("%d\n",ans);
		}else{
			char opt[3];int x;
			scanf("%d%s",&x,&opt);
			add(s[x]-'a',x,-1);
			add(opt[0]-'a',x,1);
			s[x]=opt[0];
		}
	}
	return 0;
}

