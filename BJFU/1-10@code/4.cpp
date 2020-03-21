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

bool cmp(node a,node b){
    return a.price > b.price;
}

int main() {
    redirect();

    ll num; string book; double price;
    int n = 0;

    cin>>n;
    for( int i=1;i<=n;i++ ) {
        if( num==0 && book=="0" && price==0 ) break;

        cin>>num>>book>>price;

        List[i].num = num, List[i].book = book, List[i].price = price;
    }

    for(int i=n;i>=1;i--){
        List[i].out();
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/