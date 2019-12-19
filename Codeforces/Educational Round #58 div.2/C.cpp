#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r,home,num;
} seg[100010];

bool cmp(node a,node b){
	return a.l<b.l;
}

bool cmp2(node a,node b){
	return a.num<b.num;
}

inline int read(){
	int x=0,f=1;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		x*=10;x=x+t-'0';
		t=getchar();
	}
	return x*f;
}

int main(){
	int T;int n;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			//memset(seg,0,sizeof(seg));
			n=read();
			for(int i=1;i<=n;i++){
				seg[i].l=read();seg[i].r=read();
				seg[i].num=i;
			}
			sort(seg+1,seg+n+1,cmp);
			
			int ar=0,br=0;
			seg[1].home=1;ar=seg[1].r;
			for(int i=2;i<=n;i++){
				if(ar>br){
					if(seg[i].l<=ar) seg[i].home=1,ar=max(ar,seg[i].r);
					else seg[i].home=2,br=max(br,seg[i].r);
				}
				else{
					if(seg[i].l<=br) seg[i].home=2,br=max(br,seg[i].r);
					else seg[i].home=1,ar=max(ar,seg[i].r);
				}
			}
			
			int flag=0;
			if(br==0) flag=1;
			sort(seg+1,seg+n+1,cmp2);
			if(flag==1) printf("-1\n");
			else{
				for(int i=1;i<=n;i++) printf("%d ",seg[i].home);
				printf("\n");
			} 
		}
	} 
	return 0;
}
