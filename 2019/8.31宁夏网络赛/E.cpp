#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

const int MAXN=5005;

struct node
{
    int fa,type,val[4],son[4];
}s[MAXN];

int root,tot;
void init()
{
    root=tot=0;
}
int newnode(int x)
{
    tot++;
    s[tot].fa=0;
    s[tot].type=2;
    s[tot].val[0]=x;
    memset(s[tot].son,0,sizeof(s[tot].son));
    return tot;
}
bool is_leaf(int u)
{
    for(int i=0;i<s[u].type;i++)
        if(s[u].son[i])return 0;
    return 1;
}
void insert(int u,int v)
{
    if(s[u].type==4)
    {
        int f=s[u].fa,t=s[u].val[1];
        int lef=u,rig=newnode(s[u].val[2]);
        s[lef].type=2;
        s[rig].fa=f;
        s[rig].son[0]=s[lef].son[2];
        s[rig].son[1]=s[lef].son[3];
        s[s[rig].son[0]].fa=rig;
        s[s[rig].son[1]].fa=rig;
        if(!f)
        {
            root=newnode(t);
            s[lef].fa=root;
            s[rig].fa=root;
            s[root].son[0]=lef;
            s[root].son[1]=rig;
            u=root;
        }
        else
        {
            s[f].type++;
            s[f].val[s[f].type-2]=t;
            s[f].son[s[f].type-1]=rig;
            sort(s[f].val,s[f].val+s[f].type-1);
            sort(s[f].son,s[f].son+s[f].type,[](int x,int y)
                 {
                     return s[x].val[0]<s[y].val[0];
                 });
            u=f;
        }
    }
    else if(is_leaf(u))
    {
        s[u].type++;
        s[u].val[s[u].type-2]=v;
        sort(s[u].val,s[u].val+s[u].type-1);
        return;
    }
    int go=lower_bound(s[u].val,s[u].val+s[u].type-1,v)-s[u].val;
    insert(s[u].son[go],v);
}
void traversal(int u)
{
    if(!u)return;
    for(int i=0;i<s[u].type-1;i++)
        printf("%d%c",s[u].val[i]," \n"[i==s[u].type-2]);
    for(int i=0;i<s[u].type;i++)
        traversal(s[u].son[i]);
}

int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)
        {
            int p;
            scanf("%d",&p);
            if(!root)root=newnode(p);
            else insert(root,p);
        }
        printf("Case #%d:\n",ca);
        traversal(root);
    }
    return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

