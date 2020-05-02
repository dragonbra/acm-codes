#include <bits/stdc++.h>
using namespace std;

int main() {

    int T; int ans = 0;
    char s[110];
    scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%s",s);
        int len = strlen(s);
        for (int i=0; i<len; i++) {
            ans += s[i]-'0';
        }
        ans = ans % 9;
        printf("%d\n",ans);
    }

    return 0;
}