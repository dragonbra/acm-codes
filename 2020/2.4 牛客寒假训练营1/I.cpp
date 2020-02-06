#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,a,b,c;
char s[N]; int num[N];
ll pt[N][4];//0123~no,a,b,c

int main() {
    redirect();

    scanf("%d%d%d%d",&n,&a,&b,&c);
    scanf("%s",s+1);

    int cnt = 0;

    for(int i=1;i<=n;i++){
        if(s[i]=='n'&&s[i+1]=='i'){
            num[++cnt] = 1;
            i++; continue;
        } else if(s[i]=='c'&&s[i+1]=='o'){
            num[++cnt] = 2;
            i++; continue;
        } else {
            num[++cnt] = 0;
        }
    }

    for(int i=cnt;i>=0;i--){
        for(int k=0;k<=3;k++) pt[i][0] = max(pt[i][0],pt[i+1][k]);
        if(num[i]==1 && num[i+1]==2){
            pt[i][1] = max(pt[i][1],pt[i+1][0]+a);
            if(num[i+2]==1) {
                pt[i][2] = max(pt[i][2],pt[i+2][0]+b);
                if(num[i+3]==2 && num[i+4]==1) pt[i][3] = max(pt[i][3],pt[i+4][0]+c);
            }
        } 
    }

    //for(int i=1;i<=cnt;i++) cout<<num[i]<<' '; cout<<endl;

    //for(int i=0;i<=3;i++)
    //    for(int j=1;j<=cnt;j++) cout<<pt[j][i]<<' '; cout<<endl;

    cout<<pt[0][0]<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/