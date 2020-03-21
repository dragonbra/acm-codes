#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;
const int M = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

struct node{
    ll num;
    string book;
    double price;
    void out(){
        printf("%lld ",num);
        cout<<book;
        printf(" %.2lf\n",price);
    }
} List[N];

int main() {
    redirect();

    ll num; string book; double price;
    int cnt = 0;

    while( cin>>num>>book>>price ) {
        if( num==0 && book=="0" && price==0 ) break;
        ++cnt;

        List[cnt].num = num, List[cnt].book = book, List[cnt].price = price;
    }

    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
        List[i].out();
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/