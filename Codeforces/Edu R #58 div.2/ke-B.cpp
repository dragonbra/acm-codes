#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
static const int maxn = 100010;
static const int INF = 0x3f3f3f3f;
static const int mod = (int)1e9 + 7;
static const double eps = 1e-6;
static const double pi = acos(-1);

void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
char s[500010];
int main(){
    redirect();
    scanf("%s",s);
    int a,b,c,d,ans = 0;
    a = b = c = d = 0;
    int len = strlen(s);
    for(int i = 0;i < len;i++){
        if(s[i] == '['){
            a = i;
            for(int j = i+1;j < len;j++){
                if(s[j] == ':'){b = j;break;}
            }
            break;
        }
    }
    for(int i = len-1;i > 0 ;i--){
        if(s[i] == ']'){
            d = i;
            for(int j = i-1;j >= 0;j--){
                if(s[j] == ':'){c = j;break;}
            }
            break;
        }
    }
    if(a < d && b < c){
        for(int i = b+1;i < c;i++)if(s[i] == '|')ans++;
        printf("%d\n",ans+4);
    }
    else puts("-1");
    return 0;
}
