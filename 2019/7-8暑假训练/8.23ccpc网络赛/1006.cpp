#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
bool vis[N];int a[N],c[N];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&c[i]);
	
	for(int i=m;i>=1;i--){
		if(!vis[c[i]]){
			vis[c[i]]=true;printf("%d ",c[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[a[i]]){
			vis[a[i]]=true;printf("%d ",a[i]);
		}
	}
	
	
	return 0;
}

