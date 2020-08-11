#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "math.h"
#include "queue"
#include "vector"
#include "stack"
#include "set"
#include "map"
#include "unordered_map"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll mod=998244352;
const ll MOD=998244353;
const ll inf=1e18;
const int maxn=1e5+10;
const ull base=147;
map<pair<ll, ll>,int>mp;
queue<pair<ll,ll> > q;
pair<ll,ll>cur;
int dis[8][2];
ll gcd(ll a,ll b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    dis[0][0]=-1,dis[0][1]=-1;
    dis[1][0]=-1,dis[1][1]=0;
    dis[2][0]=-1,dis[2][1]=1;
    dis[3][0]=0,dis[3][1]=-1;
    dis[4][0]=0,dis[4][1]=1;
    dis[5][0]=1,dis[5][1]=-1;
    dis[6][0]=1,dis[6][1]=0;
    dis[7][0]=1,dis[7][1]=1;
    int T;
    scanf("%d",&T);
    while(T--){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(x==y || gcd(x,y)<=1){
            puts("0/1");
            continue;
        }
        int flag=0;
        mp.clear();

        while(!q.empty()) q.pop();

        q.push({x,y});
        mp[{x,y}]=1;

        ll fz = 0, fm = 0;
        while(!q.empty()){
            cur=q.front();q.pop();
            for(int i=0;i<8;i++){
                int nx=cur.first+dis[i][0],ny=cur.second+dis[i][1];
                if(nx==ny){
                    flag=1;
                    break;
                }
                if (gcd(nx, ny) != 1) {
                    fm ++;
                    if(mp[{nx,ny}]==0){
                        mp[{nx,ny}]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }

        cur = {x,y};
        for(int i=0;i<8;i++){
            int nx=cur.first+dis[i][0],ny=cur.second+dis[i][1];
            if (gcd(nx, ny) != 1) {
                fz ++;
                if(mp[{nx,ny}]==0){
                    mp[{nx,ny}]=1;
                    q.push({nx,ny});
                }
            }
        }

        if(flag){
            puts("0/1");
            continue;
        } else {
            printf("%lld/%lld\n", fz, fm);
        }
        
    }
    return 0;
}