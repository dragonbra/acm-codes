#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e3 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

int n,m;
char s[N][N];
struct node{
    int x,y;
} cmd[N];

int cal(char x){
    if(x>='a'&&x<='z') return x-'a';
    else return x-'A'+26;
}

char re(int x){
    if(x<=25) return x+'a';
    else return x-26+'A';
}

int main() {
    redirect();

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&cmd[i].x,&cmd[i].y);
    for(int i=1;i<=n;i++) scanf("%s",s[i]);

    for(int i=m;i>=1;i--){
        int x,y; x = cmd[i].x, y = cmd[i].y;
        int cir = strlen(s[x]), len = strlen(s[y]);
        for(int j=0;j<len;j++){
            int mk = ( cal(s[y][j]) + 52 - cal(s[x][j%cir] ) % 52;
            s[y][j] = re(mk);
        }
    }

    for(int i=1;i<=n;i++) printf("%s\n",s[i]);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/