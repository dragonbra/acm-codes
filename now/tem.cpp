#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[100001],d[100001];
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        ll ans=0;
        for(int i=2;i<=n;i++){d[i]=a[i]-a[i-1];if(d[i]>0)ans+=d[i];}
        int q,l,r;
        ll x;
        ll tick=ans;
        if((ans+a[1])%2==0)tick=(ans+a[1])/2;else tick=(ans+a[1]+1)/2;
        printf("%lld\n",tick);
        scanf("%d",&q);
        while(q--){
          scanf("%d%d%lld",&l,&r,&x);
          if(l==1)a[1]+=x;
          if(l>1){
              if(d[l]>0){
                  if(d[l]+x>0)ans=ans+x;
                  else ans=ans-d[l];
              }
              else if(d[l]<=0){
                  if(d[l]+x>0)ans=ans+x+d[l];
              }
              d[l]+=x;
          }
          if(r+1<=n){
              if(d[r+1]>0){
                  if(d[r+1]-x>0)ans=ans-x;
                  else ans=ans-d[r+1];
              }
              if(d[r+1]<=0){
                  if(d[r+1]-x>0)ans=ans+d[r+1]-x;
              }
              d[r+1]-=x;
          }
        if((ans+a[1])%2==0)tick=(ans+a[1])/2;else tick=(ans+a[1]+1)/2;
        printf("%lld\n",tick);
        }
    
}