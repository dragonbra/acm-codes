/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-05-16 15:19
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int p[N*2];
char str[N*2],t[N*2];

int Manacher(char *str,int len){
    // 初始化部分
    t[0] = '$';t[1] = '#';
    int tot = 2;
    for(int i=0; i<len; i++){
        t[tot++]=str[i];
        t[tot++]='#';
    }

    int mx = 0,id = 0,reslen = 0,resCenter = 0;
    for(int i=0; i<tot; i++){
        if(i<mx) p[i] = min(p[2*id - i] , mx - i); // 2*id - i = id - (i-id); j和i关于id对称;
        else p[i] = 1; // i比mx大了，也就是当前最大的回文串够不着它了

        while( t[i+p[i]] == t[i-p[i]] ) p[i] ++; // 计算i为中心大时候，最大的回文字串有多大
        if(p[i]+i > mx){
            mx = i + p[i];
            id = i;
        }

        if(reslen < p[i]) {
            reslen = p[i], resCenter = i;
        }

    }
    return reslen;
}

int main(){
    while(~scanf("%s", str)){
        int len = strlen(str);
        printf("%d\n",Manacher(str,len)-1);
    }
    return 0;
}
