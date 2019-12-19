#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;

int n,m,len;
int a[N];

struct node{
	int l,r;
	int lazy;
	void update(int x){
		if(l==r) a[l]+=x;
		lazy+=x;
	}
} tree[4*N];

void push_down(int x){
	int lazyval=tree[x].lazy;
	if(lazyval){
		tree[x<<1].update(lazyval);
		tree[x<<1|1].update(lazyval);
		tree[x].lazy=0;
	}
}

void update(int x,int l,int r,int val=1){
	int L=tree[x].l,R=tree[x].r;
	if(l<=L&&R<=r){
		tree[x].update(val);
	}else{
		push_down(x);
		int mid=(L+R)/2;
		if(mid>=l) update(x<<1,l,r,val);
		if(r>mid) update(x<<1|1,l,r,val);
	}
}

void build(int x,int l,int r){
	tree[x].l=l;tree[x].r=r;
	tree[x].lazy=0;
	if(l==r){
		//hha
	}else{
		int mid=(l+r)/2;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
	}
}

void query(int x,int num){
	int L=tree[x].l,R=tree[x].r;
	if(L==R){
		printf("%d\n",a[L]); 
		return;
	}else{
		push_down(x);
		int mid=(L+R)/2;
		if(mid>=num) query(x<<1,num);
		if(num>mid) query(x<<1|1,num);
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&len);
	build(1,0,200000);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(y<=len){
			int l,r;
			l=x-(len-y),r=x+(len-y);
			if(l<0) l=0;
			//cout<<l<<' '<<r<<endl;
			update(1,l,r);
		}
	}
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		query(1,x);
	}
	return 0;
}
