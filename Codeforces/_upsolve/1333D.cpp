#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,k;
int mini = 0, maxi = 0; 
char s[N]; int a[N];

int main() {
    redirect();

    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        if(s[i]=='L') a[i] = 0;
        else a[i] = 1;
    }

    int cnt = 0, last = 0;
    for (int i = n; i >= 1; --i) {
        if (a[i] == 0) {
            ++cnt;
        } else {
            if (cnt == 0) continue;
            maxi += cnt;
            mini = max(cnt, last + 1);
            last = mini;
        }
    }

    cout<<mini<<endl;

    if(k<mini || k>maxi) {
        puts("-1");
        return 0;
    }

    queue<int> Q; bool f = 0; 
    for(int i=k;i>=1;i--) {
        //cout<<i << " "<< maxi<<endl;
        if( f ) {
            int x = Q.front(); Q.pop();
            printf("1 %d\n",x);
            a[x] = 0; a[x+1] = 1;
            if (x - 1 >= 1 && a[x - 1] == 1) { Q.push(x - 1); }
            if (x + 2 <= n && a[x + 2] == 0) { Q.push(x + 1); }

        } else {

            while(!Q.empty()) Q.pop();
            for(int j=1;j<n;j++) if(a[j]==1&&a[j+1]==0) Q.push(j);
            int times = min((int)Q.size(), maxi-(i-1) );
            maxi -= times;
            printf("%d ",times);
            for(int j=1;j<=times;j++) {
                int x = Q.front(); Q.pop();
                printf("%d ",x);
                a[x] = 0; a[x+1] = 1;
            }
            printf("\n");

            if(maxi==i-1) {
                f = 1;
                while(!Q.empty()) Q.pop();
                for(int j=1;j<n;j++) if(a[j]==1&&a[j+1]==0) Q.push(j);
            }
            
        }
        
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/