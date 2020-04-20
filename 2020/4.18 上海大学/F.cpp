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

const int a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int Day(int year, int month, int day){
	int ret = 0;
	int c, y, m, d;
	if(month <= 2){
		c = ( year - 1 ) / 100;
		y = ( year - 1 ) % 100;
		m = month + 12;
		d = day;
	}
	else{
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
	}
	ret = y + y / 4 + c / 4 - 2 * c + 26 * ( m + 1 ) / 10 + d - 1;
	ret = ret >= 0 ? ( ret % 7 ) : ( ret % 7 + 7 );
	return ret;
}

int n; 
struct node{
    int y,m,d;

    node(){}

    node (int Y,int M,int D) {
        y = Y; m = M; d = D;
    }

    void out(){
        if(m==5) cout<<"Mother's Day: May "<<d<<"th, "<<y<<endl;
        if(m==6) {
            cout<<"Father's Day: June ";
            if(d==21) cout<<"21st, ";
            else cout<<d<<"th, ";
            cout<<y<<endl;
        }
    }
} s[N];

int main() {
    redirect();

    cin>>n;
    for(int i=1;i<=n;i++) {
        node t;
        cin>>t.y>>t.m>>t.d;

        node cmp = node(t.y,t.m,t.d);
        bool f = true;

        if( t.m==5 ) {
            if( t.d>=8 && t.d<=14 ){ 
                for(int i=t.d+1;i<=14;i++) {
                    cmp.d = i;
                    int no = Day(cmp.y,cmp.m,cmp.d);
                    if(no%7==0) {
                        f = false;
                        cmp.out();
                    }
                }
            } 
        } 

        if( t.m==6 ) {
            if( t.d>=15 && t.d <= 21 ) {
                for(int i=t.d+1;i<=21;i++) {
                    cmp.d = i;
                    int no = Day(cmp.y,cmp.m,cmp.d);
                    if(no%7==0) {
                        f = false;
                        cmp.out();
                    }
                }
            }
        }

        if(f) {
            if(t.m<5) cmp.m = 5;
            else if(t.m==5 && t.d>7) cmp.m = 6;
            else if(t.m==6 && t.d>14) cmp.y ++, cmp.m = 5;
            else if(t.m>6) cmp.y ++, cmp.m = 5;

            if(cmp.m==5) {
                for(int i = 8;i<=14;i++){
                    cmp.d = i;
                    int no = Day(cmp.y,cmp.m,cmp.d);
                    //cout<<no<<": ";cmp.out();
                    if(no%7==0) {
                        cmp.out();
                        break;
                    }
                }
            } else if(cmp.m==6) {
                for(int i=15;i<=21;i++) {
                    cmp.d = i;
                    int no = Day(cmp.y,cmp.m,cmp.d);
                    if(no%7==0) {
                        cmp.out();
                        break;
                    }
                }
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