#include<bits/stdc++.h>
#define fst first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
const int maxn = 2e6+100;
PLL a[maxn],b[maxn];
ll f[maxn];
int n,q[maxn];
bool cmp(PLL a, PLL b){return a.fst==b.fst?a.sc<b.sc:a.fst<b.fst;}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &a[i].fst, &a[i].sc);
    }
    sort(a+1,a+1+n,cmp);
    int tot=0;
    for(int i = 1; i <= n; i++){
        while(tot&&a[i].sc>=b[tot].sc)tot--;
        b[++tot]=a[i];
    }
    int l=0,r=0;
    for(int i = 1; i <= tot; i++){
        while(l<r&&(f[q[l+1]]-f[q[l]])<=b[i].fst*(b[q[l]+1].sc-b[q[l+1]+1].sc))l++;
        int j = q[l];
        f[i]=f[j]+b[i].fst*b[j+1].sc;
        while(l<r&&(f[q[r]]-f[q[r-1]])*(b[q[r]+1].sc-b[i+1].sc)>=(f[i]-f[q[r]])*(b[q[r-1]+1].sc-b[q[r]+1].sc))r--;
        q[++r]=i;
    }
    printf("%lld",f[tot]);
    return 0;
}