#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
}

struct node{
    int idx, v;
    node(int idx,int v):idx(idx),v(v){}
    bool operator < (const node &a) const{
        if(v!=a.v) return v < a.v;
        return idx < a.idx; 
    }
} a[N];

bool cmp(node a,node b){
    if(a.v!=b.v) return a.v>b.v;
    return a.idx>b.idx;
}
int n,cnt[N];
int C[N];
ll ans[N];

int lowbit(int k){return k&-k;}

void add(int i,int val){
    while(i<=n){
        C[i]+=val;
        i +=lowbit(i);
    }
}

int sum(int i){
    int s = 0;
    while(i>0){
        s+=C[i];
        i-=lowbit(i);
    }
    return s;
} 

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i].v); a[i].idx = i;
    }

    sort(a+1,a+n+1,cmp);

    int sz=0;
    for(int i=1;i<=n;i++){
        ans[n-1] += sum(a[i].idx);
        cnt[a[i].v] += sum(a[i].idx);
        add(a[i].idx,1);
    }

    for(int i=n-2;i>=0;i--){
        ans[i] = ans[i+1] - cnt[i];
    }

    for(int i=0;i<n;i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}