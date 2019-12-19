#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect() {
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
}
inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}
int f[50],sum[50],vis[50],head[50];
int k[50][50];
int cnt,nn,nmax,nnn,flag,fflag;
map<int,string>mmap;
map<string,int>nmap;
string s,t;
struct arr{
	int to,next;
}edge[50];
void add(int x,int y){
	cnt++;
	edge[cnt].to=y,edge[cnt].next=head[x];
	head[x]=cnt;
}
void topu(int n){
	queue<int>q;
	int tot=0;
	for(int i=1;i<=nnn;i++)f[i]=sum[i];
	for(int i=1;i<=nnn;i++)if(!sum[i])q.push(i),tot++,vis[i]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=edge[i].next){
			f[edge[i].to]--;
			if(!f[edge[i].to])q.push(edge[i].to),tot++;
		}
	}
	if(tot==nnn && n==2*nn-1)puts("0");
	else if(tot!=nnn)flag=1;
}
int main() {
	//redirect();
	while(~scanf("%d",&nn)){
		cnt=0;nmax=0;nnn=0;fflag=0;
		memset(k,0,sizeof(k));
		mmap.clear();nmap.clear();
		memset(head,-1,sizeof(head));
		memset(sum,0,sizeof(sum));
		
		bool fd=0;
		for(int i=1;i<=2*nn;i+=2){
			memset(vis,0,sizeof(vis));
			flag=0;
			cin>>s;
			if(nmap[s]==0){
				 nnn++;
				mmap[nnn]=s;
				nmap[s]=nnn;
				nmax=max(nmax,nnn);
			}
			cin>>t;
			if(nmap[t]==0){
				nnn++;
				mmap[nnn]=t;
				nmap[t]=nnn;
				nmax=max(nmax,nnn);
			}
			add(nmap[s],nmap[t]);sum[nmap[t]]++;
			topu(i);
			if(!fd&&flag){
					 fd=1; cout<<s<<" "<<t<<endl;
				}
  }
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

