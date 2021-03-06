/*

DSU-on-tree
树上启发式合并
重点：{
    dfs1()：找出所有节点的重儿子，记录每个节点的子树大小
    dfs2()：搜索下去更新答案，
        如果是重儿子，
            将兄弟所有的集合合并到重儿子，并将重儿子的答案合并到父亲节点
        else 如果是轻儿子
            寻找他的重儿子并先把答案合并到自己
}

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,f[N];
int son[N], size[N];
ll ans[N], rans[N];

vector<int> G[N];
set<ll> S[N];

void merge(int a,int b) {
    while(!S[b].empty()){
        ll t = *( S[b].begin() ); S[b].erase( t );

        ll up=0, low=0;

        if( S[a].upper_bound(t) == S[a].begin() ) {
            up = *S[a].begin();
            ans[a] += ( up - t ) * ( up - t );
        } else if( S[a].upper_bound(t) == S[a].end() ) {
            low = * ( --S[a].lower_bound(t) );
            ans[a] += ( t - low ) * ( t - low );
        } else {
            up = * ( S[a].upper_bound(t) ); low = * ( --S[a].lower_bound(t) ) ;
            ans[a] -= ( up - low ) * ( up - low ); ans[a] += ( up - t ) * ( up - t ); ans[a] += ( t - low ) * ( t - low );
        }

        S[a].insert(t);
    }
}

void dfs1(ll u, ll fa) {//记录了所有子树的size 和 每个节点的重儿子
    size[u] = 1;
    for ( auto v:G[u] ) {
        dfs1(v, u);
        size[u] += size[v];
        if ( size[v] > size[son[u]] ) son[u] = v;
    }
}

void dfs2(ll u,ll fa,bool keep,bool isson){
    for( auto v:G[u] ) {
        if( v!=son[u] ){
            dfs2(v,u,0,0);
        }
    }

    if( son[u] ) {
        dfs2(son[u],u,1,1);
    }

    if( keep ) {
        for( auto v:G[fa] ) {
            if( u==v ) continue;
            merge( u, v );
        }

        if( S[fa].size() < S[u].size() ) S[fa].swap(S[u]), swap(ans[fa],ans[u]);
        merge( fa, u ); 
        rans[fa] = ans[fa];
    }
}

int main() {
    redirect();

    scanf("%d",&n); f[1] = 1; S[1].insert(1);
    for(ll i=2;i<=n;i++){
        scanf("%d",&f[i]);
        G[ f[i] ].push_back(i); S[i].insert(i);
    }

    dfs1(1,1);
    dfs2(1,1,0,0);

    for(ll i=1;i<=n;i++) {
        printf("%lld\n",rans[ i ]);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/