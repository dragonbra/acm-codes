#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5+10;
int a[N];LL sum=0;int ans=0;
int Q;int n,m;
priority_queue<int> q;

int main(){
	scanf("%d",&Q);
	while(Q--){
		q=priority_queue<int>();ans=0;sum=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			while(sum>m){
				int t=q.top();q.pop();
				sum-=t;ans++;
			}
			q.push(a[i]);
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}
