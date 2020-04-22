#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

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
};

priority_queue<node> Q;
int n, a[N],cnt[N];
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
        scanf("%d",&a[i]);
        Q.push(node(i,a[i]));
    }

    int sz=0;
    while(!Q.empty()){
        node x = Q.top(); Q.pop();
        ans[n-1] += sum(x.idx);
        cnt[x.v] += sum(x.idx);
        add(x.idx,1);
    }

    for(int i=n-2;i>=0;i--){
        ans[i] = ans[i+1] - cnt[i];
    }

    for(int i=0;i<n;i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}