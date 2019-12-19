#include <bits/stdc++.h>
using namespace std;
const int N =2e5+10;
struct node{
	int l,r;
	bool operator < (const node b) const{
		if(r!=b.r) return r>b.r;
		return l>b.l; 
	}
} a[N];
priority_queue<node> Q;
bool cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r; 
}
struct query{
	int x,num,ans;
} q[N];
bool cmp2(query a,query b){
	return a.x<b.x;
}
bool cmp3(query a,query b){
	return a.num<b.num;
}
int n,m,l;

int main(){
	Q=priority_queue<node>();
	scanf("%d %d %d",&n,&m,&l);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d %d",&x,&y);
		if(y<=l){
			int ll=x-(l-y),rr=x+(l-y);
			if(ll<1) ll=1;
			a[i].l=ll;a[i].r=rr;
		}else{
			a[i].l=a[i].r=0;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		scanf("%d",&q[i].x);q[i].num=i;
	}
	sort(q+1,q+m+1,cmp2);
	int pt=1;
	for(int i=1;i<=m;i++){
		while(a[pt].l<=q[i].x&&pt<=n){
			Q.push(a[pt]);
			pt++;
		}
		while(!Q.empty()&&Q.top().r<q[i].x){
			Q.pop();
		}
		q[i].ans=Q.size();
	}
	sort(q+1,q+m+1,cmp3);
	for(int i=1;i<=m;i++){
		printf("%d\n",q[i].ans);
	}
	
	return 0;
}
