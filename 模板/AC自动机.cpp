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
const int N = 1e6+10;

void redirect() {
    #ifdef LOCAL
        //freopen("test.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
}
inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

struct Trie {
    int next[N][26],fail[N],end[N];
    int root,L;
    int newnode(){
        for(int i=0;i<26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init(){
        L = 0;
        root = newnode();
    }
    void insert(char buf[]){
        int len = strlen(buf);
        int now = root;
        for(int i=0;i<len;i++){
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build(){
        queue<int>Q;
        fail[root] = root;
        for(int i=0;i<26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() ) {
            int now = Q.front();
            Q.pop();
            for(int i=0;i<26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[]){
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i=0;i<len;i++){
            now = next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root ) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug(){
        for(int i = 0;i < L;i++){
            printf("id␣=␣%3d,fail␣=␣%3d,end␣=␣%3d,chi␣=␣[",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
char buf[N];
Trie ac;

int main() {
	redirect();
	int T; scanf("%d",&T);
	int n;
	while ( T-- ) {
        scanf("%d",&n);
        ac.init();
        for(int i=0;i<n;i++){
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("%d\n",ac.query(buf));
	}
}

/*
-------------------
 author:dragon_bra
-------------------
*/
