#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
#include "math.h"
#include "map"
#include "stack"
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll INF=1e12;
const double eps=1e-6;
int n,m;
ll k;
ll vvis[110],vis[80];
ll a[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&k);
        memset(vvis,0,sizeof(vvis));
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]==0)continue;
            else{
                ll t=a[i];
                int x=0;
                memset(vis,0,sizeof(vis));
                while(t){
                    vis[x]=t%k;
                    t/=k;
                    x++;
                }
                for(int i=0;i<=x;i++)
                    if(vis[i]==1){
                        if(vvis[i]==1)flag=0;
                        else vvis[i]=1;
                    }else if(vis[i]!=0)flag=0;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}
