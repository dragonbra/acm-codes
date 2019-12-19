#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;

int _root,_sz;int Q,n,m;
int _fa[N],_s[N][2],_cnt[N],_size[N];ll _sum[N];int _a[N];

inline int ws(int x) {return _s[_fa[x]][1]==x;}//which son 
void setson(int son,int f,int w){//0-left,ะก;1-right,ด๓;
	if(son!=0) _fa[son]=f;
	if(f!=0) _s[f][w]=son;
}
void maintain(int x){
	_size[x]=_size[_s[x][0]]+_size[_s[x][1]] + _cnt[x];
	_sum[x]=_sum[_s[x][0]] + _sum[_s[x][1]] + _cnt[x]*_a[x];
}
void rot(int x){
	int f=_fa[x]; int ff=_fa[f]; int w=ws(x); int wf=ws(f);
	int p=_s[x][!w];
	setson(p,f,w);
	setson(x,ff,wf);
	setson(f,x,!w);//!w
	maintain(f);
	maintain(x);
}
void splay(int x){
	for(;_fa[x];rot(x)) 
		if(_fa[_fa[x]]&&ws(_fa[x])==ws(x)) rot(_fa[x]);
	
	//zig-zag or zig-zig
	_root=x;
}
void insert(int now,int p){
	if(_root==0){
		_root=++_sz;
		_sum[_sz]=_a[_sz]=p;
		_size[_sz]=_cnt[_sz]=1;
		return;
	}
	while(_a[now]!=p){
		_size[now]++;
		if(p>_a[now]){
			if(_s[now][1]==0){
				_a[++_sz]=p;
				setson(_sz,now,1);
			}
			now=_s[now][1];
		}
		else{
			if(_s[now][0]==0){
				_a[++_sz]=p;
				setson(_sz,now,0);
			}
			now=_s[now][0];
		}
	}
	
	_size[now]++; _cnt[now]++;
	splay(now);
}

int Rank(int now,int cmp){
	int rec=0;
	while(now){
		if(_sum[_s[now][0]]>=cmp){
			now=_s[now][0];
		}
		else{
			rec+=_size[_s[now][0]];
			cmp-=_sum[_s[now][0]];
			if(_a[now]*_cnt[now]>=cmp){
				return rec+cmp/_a[now];
			}
			rec+=_cnt[now];
			cmp-=(_a[now]*_cnt[now]);
			now=_s[now][1];
		}
	}
	return rec;
}

int main(){
	scanf("%d",&Q);
	while(Q--){
		_root=0;_sz=0;
		memset(_fa,0,sizeof(_fa));
		memset(_s,0,sizeof(_s));
		memset(_a,0,sizeof(_a));
		memset(_cnt,0,sizeof(_cnt));
		memset(_sum,0,sizeof(_sum));
		memset(_size,0,sizeof(_size));
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			printf("%d ",i-1-Rank(_root,m-t));
			insert(_root,t);
		}
		printf("\n");
	}
	return 0;
}
