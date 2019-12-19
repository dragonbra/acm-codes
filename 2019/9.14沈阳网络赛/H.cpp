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

struct Node {
	string name;
	
	int tp;
	int v1,v2,v3;
} a[N];

bool cmp(Node a,Node b){
	if(a.tp!=b.tp) return a.tp>b.tp;
	else if(a.v1!=b.v1) return a.v1>b.v1;
	else if(a.v2!=b.v2) return a.v2>b.v2;
	else if(a.v3!=b.v3) return a.v3>b.v3;
	else return a.name < b.name;
}

int v1,v2,v3;
int n;int cnt[15];

bool j_8(){
	if(cnt[10]==1&&cnt[11]==1&&cnt[12]==1&&cnt[13]==1&&cnt[1]==1) return true;
	return false;
}

bool j_7(){
	for (int i=13;i>=5;i--) {
		if(cnt[i]==1&&cnt[i-1]==1&&cnt[i-2]==1&&cnt[i-3]==1&&cnt[i-4]==1) {
			v1=i;return true;
		}
	}
	return false;
}

bool j_6(){
	for (int i=1;i<=13;i++) {
		if(cnt[i]==4) {
			v1=i;
			for(int j=1;j<=13;j++) if(cnt[j]==1) v2=j;
			return true;
		}
	}
	return false;
}

bool j_5(){
	for (int i=1;i<=13;i++) {
		for(int j=1;j<=13;j++) {
			if(cnt[i]==3&&cnt[j]==2){
				v1=i;v2=j; return true;
			}
		}
	}
	return false;
}

bool j_4(){
	int res=0;bool f=0;
	for (int i=1;i<=13;i++) {
		if(cnt[i]==3) v1=i,f=1;;
	}
	if(f) {
		for(int i=1;i<=13;i++) {
			if(cnt[i]&&i!=v1) res+=i;
		}
		v2=res;
		return true;
	}
	return false;
}

bool j_3(){
	bool f=0;
	for(int i=1;i<13;i++) {
		for(int j=i+1;j<=13;j++) {
			if(cnt[i]==2&&cnt[j]==2) {
				v1=j;v2=i;f=1;
			}
		}
	}
	if(f) {
		for(int i=1;i<=13;i++) {
			if(cnt[i]==1) v3=i;
		}
		return true;
	}
	return false;
}

bool j_2(){
	int res=0; bool f=0;
	for(int i=1;i<=13;i++) {
		if(cnt[i]==2) v1=i,f=1;
	}
	if(f) {
		for(int i=1;i<=13;i++) {
			if(cnt[i]==1) res+=i;
		}
		v2=res;
		return true;
	}
	return false;
}

bool j_1(){
	int res=0;
	for(int i=1;i<=13;i++) {
		if(cnt[i]) res+=i;
	}
	v1=res;
	return true;
}

int main() {
	redirect();
	while (~scanf("%d",&n)) {
		for(int i=1;i<=n;i++) {
			string t; int s[10];
			cin>>a[i].name>>t; a[i].v1=a[i].v2=a[i].v3=0;

			int k=0;
			for(int j=0;j<t.length();j++) {
				if(t[j]=='A') s[++k]=1;
				else if(t[j]=='J') s[++k]=11;
				else if(t[j]=='Q') s[++k]=12;
				else if(t[j]=='K') s[++k]=13;
				else if(t[j]=='1'&&t[j+1]=='0') {
					s[++k]=10;j++;
				}
				else s[++k]=t[j]-'0';
			}
			sort(s+1,s+k+1);
			for(int j=1;j<=14;j++) cnt[j]=0;
			for(int j=1;j<=5;j++) cnt[s[j]]++;
			
			//judge tp
			if(j_8()) a[i].tp=8;//royal straight;
			else if(j_7()) {
				a[i].tp=7; a[i].v1=v1;//straight highest card;
			} else if(j_6()) {
				a[i].tp=6; a[i].v1=v1; a[i].v2=v2;//four of a kind; 4card; remain card;
			} else if(j_5()) {
				a[i].tp=5; a[i].v1=v1; a[i].v2=v2;//full house; 3card; 2card;
			} else if(j_4()) {
				a[i].tp=4; a[i].v1=v1; a[i].v2=v2;//three of a kind; 3card; remain sum;
			} else if(j_3()) {
				a[i].tp=3; a[i].v1=v1; a[i].v2=v2; a[i].v3=v3;//two pairs; 2card high; 2card low;
			} else if(j_2()) {
				a[i].tp=2; a[i].v1=v1; a[i].v2=v2;//pair; 2card; remain sum;
			} else if(j_1()){
				a[i].tp=1; a[i].v1=v1;//high card; remain sum;
			}
			
			//cout<<a[i].name<<' '<<a[i].tp<<' '<<a[i].v1<<' '<<a[i].v2<<' '<<a[i].v3<<endl;
			
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) cout<<a[i].name<<endl;
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

