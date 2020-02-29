#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

char s[N];
int ans; int cnt;

int main() {
    redirect();

    while(~scanf("%s",s)){
        int len = strlen(s);
        if(s[0]=='|') ans+=len*42;
        else if(s[0]>'0'&&s[0]<='9'){
            int x = 0; int num = 0; int i;
            for(i=0;s[i]>='0'&&s[i]<='9';i++){
                x*=10; x+=s[i]-'0';
            }
            for(;i<len;i++){
                if(s[i]=='|') num++;
            }
            //cout<<x<<endl;
            ans += x*num;
        }
    }

    ans = (ans+9) /10 * 10;

    printf("%d,-\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/