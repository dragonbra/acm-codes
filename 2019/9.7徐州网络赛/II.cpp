#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;
vector<int> v[N];
int n,m,p[N],pos[N],mid[N];
ll sum[N];
int lowb(int x) {
    return x&(-x);
}
void up(int x,ll z) {
    while(x<=n) {
        sum[x]+=z;
        x+=lowb(x);
    }
}
ll qu(int x) {
    ll ans=0;
    while(x) {
        ans+=sum[x];
        x-=lowb(x);
    }
    return ans;
}
struct Q {
    int id,l,r;
    ll ans;
    bool operator <(Q B)const {
        return r<B.r;
    }
} q[N];
bool cmp(Q A,Q B) {

    return A.id<B.id;
}
int main() {
	#ifdef LOCAL
        freopen("test.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=2; 1LL*j*p[i]<=n; j++) {
            int t=j*p[i];
            v[t].push_back(i);
            v[p[i]].push_back(pos[t]);
        }
    }
    for(int i=1; i<=n; i++) {
        sort(v[i].begin(),v[i].end());
    }
    for(int i=1; i<=m; i++) {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    int c=1;
    for(int i=1; i<=n; i++) {
        int x=p[i];
        int j;
        for(j=mid[x]; j<v[x].size(); j++) {
            if(v[x][j]<i)up(v[x][j],1);
            else {
                break;
            }
        }
        mid[x]=j;
        while(c<=m&&q[c].r==i) {
            q[c].ans=qu(i)-qu(q[c].l-1);
            c++;
        }
    }
    sort(q+1,q+m+1,cmp);
    for(int i=1; i<=m; i++)printf("%lld\n",q[i].ans);
    return 0;
}
