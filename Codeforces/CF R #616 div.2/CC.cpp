#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
int a[N];
int main() {
    //redirect();
    int n,m,k,t,minv,maxv;
    scanf("%d",&t);
    while(t--){
        maxv=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        k=min(k,m-1);
        for(int i=0;i<=k;i++){
            minv=INF;
            for(int j=0;j<=m-k-1;j++){
                minv=min(minv,max(a[i+j+1],a[i+j+1+n-m]));
            }
            maxv=max(maxv,minv);
        }
        printf("%d\n",maxv);
    }
}
