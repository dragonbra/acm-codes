#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
const int M=MAXN*30;
int n,q,m,tot;
long long a[MAXN],t[MAXN];
long long T[MAXN],lson[M],rson[M],c[M];
long long sum[M];
long long pre[MAXN], init[MAXN];
long long res = 0;

void Init_hash(){
    for(int i=1;i<=n;i++){
        t[i] = a[i];
    }
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}

int build(int l,int r){
    int root=tot++;
    c[root]=0; sum[root] = 0;
    if(l!=r){
        int mid=(l+r)>>1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}

int Hash(int x){
    return lower_bound(t+1,t+1+m,x)-t;
}

int update(int root,int pos, int val){
    int newroot = tot++,tmp = newroot;
    c[newroot] = c[root] + val;
    sum[newroot] = sum[root] + t[pos];
    int l=1,r=m;
    while(l<r){
        int mid = (l+r)>>1;
        if(pos <= mid){
            lson[newroot]= tot++; rson[newroot] = rson[root];
            newroot = lson[newroot];root = lson[root];
            r = mid;
        }
        else{
            rson[newroot] = tot++; lson[newroot] = lson[root];
            newroot = rson[newroot]; root = rson[root];
            l = mid+1;
        }
        c[newroot] = c[root] + val;
        sum[newroot] = sum[root] + t[pos];
    }
    return tmp;
}

long long query(int left_root,int right_root,int k){
    int l=1,r=m;
    res = 0;
    while( l < r ){
        int mid = (l+r)>>1;
        if(c[lson[left_root]]-c[lson[right_root]]>=k){
            r = mid;
            left_root = lson[left_root];
            right_root = lson[right_root];
        }
        else{
            l = mid + 1;
            k -= c[lson[left_root]]-c[lson[right_root]];
            res += sum[lson[left_root]] - sum[lson[right_root]];
            left_root = rson[left_root];
            right_root = rson[right_root];
        }
    }
    res += 1ll * (k-1) * t[l];
    return res;
}
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    for (long long i=1; i<=1e5; i++) {
        init[i] = init[i-1] + i*i;
    }
    int TT; cin >> TT;
    while (TT--) {
        cin >> n;
        tot = 0;
        for(int i = 1; i <= n;i++){
            scanf("%lld",&a[i]);
            pre[i] = pre[i-1] + a[i];
        }
        Init_hash();
        T[n+1] = build(1,m);
        for(int i = n;i ;i--){
            int pos = Hash(a[i]);
            T[i] = update(T[i+1], pos ,1);
        }
        cin >> q;
        while(q--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            k = (r-l+1 + 1) - k; // 第k小变成第k大
            long long ans = pre[r] - pre[l-1] - query(T[l], T[r+1], k);
            ans += init[r-l+1];
            printf("%lld\n",ans);
        }
    }
}