#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e6 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

char s[N];

int main() {
    redirect();

    cin>>s;
    int cnt[5];
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='(') cnt[1]++;
        else if(s[i]==')') cnt[1]--;
        else if(s[i]=='[') cnt[2]++;
        else if(s[i]==']') cnt[2]--;
        else if(s[i]=='{') cnt[3]++;
        else if(s[i]=='}') cnt[3]--;
    }

    if(cnt[1]==0&&cnt[2]==0&&cnt[3]==0) puts("Yes");
    else puts("No");

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/