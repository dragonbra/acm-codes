#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rint register int
#define inv inline void
#define ini inline int
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
istream& operator>>(istream& in,P& A){
	in>>A.first>>A.second;
	return in;
}
static const double pi=acos(-1.0);
static const ll mod=ll(1e9+7);
static const int inf=0x7fffffff;
static const int maxn=0x3f3f3f3f;
static const ll maxnll=0x3f3f3f3f3f3f3f3f;
static const int tran[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
ini read(){
    rint f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}

const int N = 1e5+10;int n;ll lll,rrr;

struct node {int l, r, Cnt;}tree[N*20];

int Len, M, saaaaaa[N], gaotamaderank[N], hhh[N], tax[N], tp[N];
int tot, Log[N], Root[N], Rmq[N][21];
ll Sum[N];
char S[N];

bool cmp(int *f, int x, int y, int w) { return f[x] == f[y] && f[x + w] == f[y + w];}

void init(){
	memset(saaaaaa,0,sizeof(saaaaaa));
	memset(tax,0,sizeof(tax));
	memset(Sum,0,sizeof(Sum));
	memset(Root,0,sizeof(Root));
	Len=0;tot=0;
}

void Insert(int &Now, int l, int r, int Rt, int Side) {
    Now = ++ tot;
    tree[Now] = tree[Rt];
    tree[Now].Cnt ++;
    if (l == r) return;
    int Mid = (l + r) >> 1;
    if (Side <= Mid) Insert(tree[Now].l, l, Mid, tree[Rt].l, Side); else
        Insert(tree[Now].r, Mid + 1, r, tree[Rt].r, Side);
}

int Query(int l, int r, int Rank, int Rl, int Rr) {
    if (l == r) return l;
    int Mid = (l + r) >> 1;
    int ll = tree[Rl].l, lr = tree[Rl].r, rl = tree[Rr].l, rr = tree[Rr].r;
    if (tree[rl].Cnt - tree[ll].Cnt >= Rank) return Query(l, Mid, Rank, ll, rl); else
        return Query(Mid + 1, r, Rank - tree[rl].Cnt + tree[ll].Cnt, lr, rr); 
}

int gaotamadenum(int l, int r, int lx, int rx, int Rl, int Rr) {
    if (rx < l || lx > r) return 0;
    if (lx <= l && rx >= r) return tree[Rr].Cnt - tree[Rl].Cnt;
    int Mid = (l + r) >> 1;
    return gaotamadenum(l, Mid, lx, rx, tree[Rl].l, tree[Rr].l) + gaotamadenum(Mid + 1, r, lx, rx, tree[Rl].r, tree[Rr].r);
}

int Min(int l, int r) {
    int Len = Log[r - l + 1];
    return min(Rmq[l][Len], Rmq[r - (1 << Len) + 1][Len]);
}

int gaotamadel(int Now, int len) {
    int l = 1, r = Now - 1, Ans = Now;
    while (l <= r) {
        int Mid = (l + r) >> 1;
        if (Min(Mid + 1, Now) >= len) Ans = Mid, r = Mid - 1; else l = Mid + 1;
    }
    return Ans;
}

int gaotamader(int Now, int len) {
    int l = Now + 1, r = Len, Ans = Now;
    while (l <= r) {
        int Mid = (l + r) >> 1;
        if (Min(Now + 1, Mid) >= len) Ans = Mid, l = Mid + 1; else r = Mid - 1;
    }
    return Ans;
}

void gaotamadek2(ll k1, ll k2) {
    int l = 1, r = Len, Ans = 0;
    while (l <= r) {
        int Mid = (l + r) >> 1;
        if (Sum[Mid] < k1) Ans = Mid, l = Mid + 1; else r = Mid - 1; 
    } 
    int len = k1 - Sum[Ans] + hhh[++ Ans];
    l = gaotamadel(Ans, len), r = gaotamader(Ans, len);
    if (l == r) {
    	if(k2>1) printf("-1\n");
        else printf("%d\n", saaaaaa[Ans]);
        return;
    }
    Ans = Query(1, Len, k2, Root[l - 1], Root[r]);
    if(Ans+rrr-lll>n) printf("-1\n");
    else printf("%d\n", Ans);
}

ll gaotamadek1(ll l, ll r) {
    int len = r - l + 1, start = l - 1, Rank = gaotamaderank[l];
    r = gaotamader(Rank, len), l = gaotamadel(Rank, len);
    ll k1 = Sum[l - 1] + len - hhh[l];
    return k1;
}

int main() {
	
	int T;scanf("%d",&T);
	while(T--){
		init();
		int q;scanf("%d%d",&n,&q);
	    scanf("%s",S+1);
	    
	    Len = strlen(S + 1);
	    for (int i = 1; i <= Len; i ++) gaotamaderank[i] = S[i], tp[i] = i;
	    M = 127;
	    
	    for (int i = 0; i <= M; i ++) tax[i] = 0;
	    for (int i = 1; i <= Len; i ++) tax[gaotamaderank[tp[i]]] ++;
	    for (int i = 1; i <= M; i ++) tax[i] += tax[i - 1];
	    for (int i = Len; i >= 1; i --) saaaaaa[tax[gaotamaderank[tp[i]]] --] = tp[i]; 
	
	    for (int i, p = 1, w = 1; p < Len; w += w, M = p) {
	        for (p = 0, i = Len - w + 1; i <= Len; i ++) tp[++ p] = i;
	        for (i = 1; i <= Len; i ++) if (saaaaaa[i] > w) tp[++ p] = saaaaaa[i] - w;
	        
	        for (int i = 0; i <= M; i ++) tax[i] = 0;
		    for (int i = 1; i <= Len; i ++) tax[gaotamaderank[tp[i]]] ++;
		    for (int i = 1; i <= M; i ++) tax[i] += tax[i - 1];
		    for (int i = Len; i >= 1; i --) saaaaaa[tax[gaotamaderank[tp[i]]] --] = tp[i]; 
			
			swap(gaotamaderank,tp),p = gaotamaderank[saaaaaa[1]] = 1;
	        for (i = 2; i <= Len; i ++) gaotamaderank[saaaaaa[i]] = cmp(tp, saaaaaa[i], saaaaaa[i - 1], w) ? p : ++ p;
	    }
	
	    int j, k = 0;
	    for (int i = 1; i <= Len; hhh[gaotamaderank[i ++]] = k)
	        for (k = k ? k - 1 : k, j = saaaaaa[gaotamaderank[i] - 1]; S[i + k] == S[j + k]; k ++);
	    
	    
	    for (int i = 1; i <= Len; i ++) Insert(Root[i], 1, Len, Root[i - 1], saaaaaa[i]);

	    for (int i = 1, j = 0; i <= Len; i <<= 1, j ++) Log[i] = j;
	    for (int i = 2; i <= Len; i++) Log[i] = max(Log[i - 1], Log[i]);
	
	    for (int i = 1; i <= Len; i ++) Rmq[i][0] = hhh[i];
	    for (int j = 1; j <= 20; j ++)
	        for (int i = 1; i <= Len - (1 << (j - 1)) + 1; i ++)
	            Rmq[i][j] = min(Rmq[i][j - 1], Rmq[i + (1 << (j - 1))][j - 1]);
	
	    for (int i = 1; i <= Len; i ++) Sum[i] = Sum[i - 1] + Len - saaaaaa[i] + 1 - hhh[i];
	    
	    
	    for(int i = 1; i <= q; i ++) {
	        ll k2;
	        scanf("%lld%lld%lld",&lll,&rrr,&k2);
	        gaotamadek2(gaotamadek1(lll,rrr),k2);
	    }
	}
	return 0;
}
