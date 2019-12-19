#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5+10;
int a[N];LL sum=0;int ans=0;
int Q;int n,m;

struct node{
    int num;
    node(int u):num(u) {}
    bool operator <(const node &v)const
    {
        return num>v.num;
    }
};
priority_queue<int> q;
priority_queue<node> p;

int main(){
	scanf("%d",&Q);
	while(Q--){
		q=priority_queue<int>();
		p=priority_queue<node>();
		ans=0;sum=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			while(sum>m){
				int t=q.top();q.pop();p.push({t});
				sum-=t;ans++;
			}
			printf("%d ",ans);
			
			if(p.empty()||p.top().num>=a[i]) q.push(a[i]);
			else{
				LL ssum=0;p.push({a[i]});sum-=a[i];ans++;
				while(ssum+p.top().num<=a[i]){
					int t=p.top().num;p.pop();q.push(t);
					sum+=t;ssum+=t;ans--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
