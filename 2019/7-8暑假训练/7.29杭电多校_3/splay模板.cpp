#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;

struct node{
	int data;
}_a[N];

bool operator < (node const &_a,node const &_b){
	return _a.data<_b.data;
}
bool operator > (node const &_a,node const &_b){
	return _a.data>_b.data;
}
bool operator == (node const &_a,node const &_b){
	return _a.data<_b.data;
}
bool operator != (node const &_a,node const &_b){
	return _a.data<_b.data;
}

int n,t,_root,_sz;
int _fa[N],_s[N][2],_cnt[N],_size[N];ll _sum[N];

inline int ws(int x){return _s[_fa[x]][1]==x;}//which son 
void setson(int son,int f,int w){//0-left,ะก;1-right,ด๓;
	if(son!=0) _fa[son]=f;
	if(f!=0) _s[f][w]=son;
}
void maintain(int x){
	_size[x]=_size[_s[x][0]]+_size[_s[x][1]] + _cnt[x];
	_sum[x]=_sum[_s[x][0]] + _sum[_s[x][1]] + (ll)_cnt[x]*_a[x].data;
}
void rot(int x){
	int f=_fa[x]; int ff=_fa[x]; int w=ws(x); int wf=ws(f);
	int p=_s[x][!w];
	setson(p,f,w);
	setson(x,ff,wf);
	setson(f,x,!w);//!w
	maintain(f);
	maintain(x);
}
void splay(int x){
	for(;_fa[x];rot(x)) if(_fa[_fa[x]]&&ws(_fa[x])==ws(x)) rot(_fa[x]);//zig-zag or zig-zig
	_root=x;
}
void insert(int now,node p){
	if(_root==0){
		_root=++_sz;
		_a[_sz]=p;
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
