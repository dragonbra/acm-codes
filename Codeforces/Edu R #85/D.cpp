#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; ll n,l,r;
int a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&l,&r);

        ll st = l, cnt = r-l+1;
        bool f = true, mk = false;
        bool f1 = true;

        for(int i=n-1;i>=1;i--){
            if(st<=i*2) f1 = false;
            if(st>i*2&&f1){
                st-=i*2; continue;
            }

            int num = 0;
            int now = n-i;
            for(int j=now+1;j<=n;j++){
                a[++num] = now;
                a[++num] = j;
            }

            if(f){
                f = false;
                //cout<<st<<' '<<num<<endl;
                for(int k = st;k<=num;k++){
                    printf("%d ",a[k]);
                    cnt--;
                    if(cnt==0) {
                        mk = true; break;
                    }
                }
            } else {
                //cout<<"Yes"<<endl;
                for(int k = 1;k<=num;k++){
                    printf("%d ",a[k]);
                    cnt--;
                    if(cnt==0) {
                        mk = true; break;
                    }
                }
            }

            if(mk) break;
        }
        //cout << st <<endl;
        if(cnt) printf("1 ");
        printf("\n");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/