#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+10;
int xv[N],yv[N];
struct node{
	int x,y;ll w;
	int rx,ry;
	node (){}
	node (int x,int y,ll w):x(x),y(y),w(w) {}
} s[N];

bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

int T,n;int xcnt,ycnt;

ll tree[N][N];  //行列分开看，每一行每一列都是一个一维树状数组
//n行m列
 
int lowbit(int x){return x&(-x);}
//单点更新,区间查询
void add(int x,int y,ll val){  //单点更新
    while(x<=N){
        for(int i=y;i<=N;i+=lowbit(i)){  //列的一维树状数组
            tree[x][i]+=val;
        }
        x+=lowbit(x);
    }
}

ll sum(int x,int y){  //返回(0,0),(x,y)为对角顶点的矩阵和
    ll res=0;
    while(x>0){
        for(int i=y;i>0;i-=lowbit(i)){
            res+=tree[x][i];
        }
        x-=lowbit(x);
    }
    return res;
}

ll query(int x1,int y1,int x2,int y2){   //区间查询
    return sum(x2,y2) + sum(x1-1,y1-1) - sum(x2,y1-1) - sum(x1-1,y2);  //容斥,注意是否可能超longlong
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(tree,0,sizeof(tree));
		xcnt=ycnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y,w;scanf("%d%d%lld",&s[i].x,&s[i].y,&s[i].w);
		}
		sort(s+1,s+n+1,cmp);
		xv[++xcnt]=s[1].x;yv[++ycnt]=s[1].y; s[1].rx=xcnt,s[1].ry=ycnt;add(1,1,s[1].w);
		for(int i=2;i<=n;i++){
			node t = s[i];
			if(t.x==s[i-1].x){
				if(t.y==s[i-1].y){
					s[i].rx=xcnt,s[i].ry=ycnt;add(xcnt,ycnt,t.w);
					
					//cout<<xcnt<<' '<<ycnt<<' '<<t.w<<endl;
				}
				else{
					int tcnt=0;
					for(int j=1;j<=ycnt;j++){if(t.y==yv[j]){ tcnt=j;break;}}
					if(tcnt==0){yv[++ycnt]=t.y;tcnt=ycnt;}
					s[i].rx=xcnt,s[i].ry=tcnt;add(xcnt,tcnt,t.w);
					
					//cout<<xcnt<<' '<<tcnt<<' '<<t.w<<endl;
				}
			}
			else{
				xv[++xcnt]=t.x;
				int tcnt=0;
				for(int j=1;j<=ycnt;j++){if(t.y==yv[j]){ tcnt=j;break;}}
				if(tcnt==0){yv[++ycnt]=t.y;tcnt=ycnt;}
				s[i].rx=xcnt,s[i].ry=tcnt;add(xcnt,tcnt,t.w);
				
				//cout<<xcnt<<' '<<tcnt<<' '<<t.w<<endl;
			}
		}
		
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll t = query(s[i].rx,s[i].ry,s[j].rx,s[j].ry);
				ans=max(ans,t);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

