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
    int cnt = 0;

    while( cin>>num>>book>>price ) {
        if( num==0 && book=="0" && price==0 ) break;
        ++cnt;

        List[cnt].num = num, List[cnt].book = book, List[cnt].price = price;
    }

    //sort(List+1,List+cnt+1,cmp);

    double ave = 0;
    for(int i=1;i<=cnt;i++){
        ave += List[i].price;
    } ave /= (double)cnt;

    printf("%.2lf\n",ave);
    for(int i=1;i<=cnt;i++){
        if( List[i].price < ave ){
            List[i].price *= 1.2;
        } else {
            List[i].price *= 1.1;
        }
        
        List[i].out();
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/