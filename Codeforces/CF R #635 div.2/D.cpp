#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; int nr,ng,nb;
ll r[N],g[N],b[N]; ll ans = 9e18;

ll cal(ll x,ll y,ll z){
    //cout<<(x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x)<<' '<<x<<' '<<y<<' '<<z<<endl;
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}

bool islegal1(int x){
    if(x>=1&&x<=nr) return true;
    return false;
}
bool islegal2(int x){
    if(x>=1&&x<=ng) return true;
    return false;
}
bool islegal3(int x){
    if(x>=1&&x<=nb) return true;
    return false;
}

int main() {
    redirect();

    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&nr,&ng,&nb);
        for(int i=1;i<=nr;i++) scanf("%lld",&r[i]);
        for(int i=1;i<=ng;i++) scanf("%lld",&g[i]);
        for(int i=1;i<=nb;i++) scanf("%lld",&b[i]);

        sort(r+1,r+nr+1);
        sort(g+1,g+ng+1);
        sort(b+1,b+nb+1);

        ans = 9e18;

        for(int i=1;i<=nr;i++){
            ll mid = r[i];
            int pos2 = lower_bound(g+1,g+ng+1,mid) - g;
            int pos3 = lower_bound(b+1,b+nb+1,mid) - b;

            if(!islegal2(pos2) && !islegal3(pos3)) break;
            
            if(g[pos2]==mid || b[pos3]==mid) {
                if(islegal2(pos2) && islegal3(pos3)) ans = min( ans, cal(mid,g[pos2],b[pos3]) );
            }

            if(islegal2(pos2-1) && islegal3(pos3)) ans = min( ans, cal(mid,g[pos2-1],b[pos3]) );
            if(islegal2(pos2) && islegal3(pos3-1)) ans = min( ans, cal(mid,g[pos2],b[pos3-1]) );
        }

        for(int i=1;i<=ng;i++){
            ll mid = g[i];
            int pos1 = lower_bound(r+1,r+nr+1,mid) - r;
            int pos3 = lower_bound(b+1,b+nb+1,mid) - b;

            if(!islegal1(pos1) && !islegal3(pos3)) break;

            if(r[pos1]==mid || b[pos3]==mid) {
               if(islegal1(pos1) && islegal3(pos3)) ans = min( ans, cal(mid,r[pos1],b[pos3]) );
            }

            if(islegal1(pos1-1) && islegal3(pos3)) ans = min( ans, cal(mid,r[pos1-1],b[pos3]) );
            if(islegal1(pos1) && islegal3(pos3-1)) ans = min( ans, cal(mid,r[pos1],b[pos3-1]) );
        }

        for(int i=1;i<=nb;i++){
            ll mid = b[i];
            int pos1 = lower_bound(r+1,r+nr+1,mid) - r;
            int pos2 = lower_bound(g+1,g+ng+1,mid) - g;

            if(!islegal1(pos1) && !islegal2(pos2)) break;

            if(r[pos1]==mid || g[pos2]==mid) {
               if(islegal1(pos1) && islegal2(pos2)) ans = min( ans, cal(mid,r[pos1],g[pos2]) );
            }

            if(islegal1(pos1-1) && islegal2(pos2)) ans = min( ans, cal(mid,r[pos1-1],g[pos2]) );
            if(islegal1(pos1) && islegal2(pos2-1)) ans = min( ans, cal(mid,r[pos1],g[pos2-1]) );
        }

        printf("%lld\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/