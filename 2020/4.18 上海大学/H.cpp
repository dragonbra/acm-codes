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

int T;
string s; int k;
int main() {
    redirect();

    cin>>T;
    while(T--) {    
        cin>>s>>k;
        int c[10]={0},m[3]={0};//0-9,012
        for(int i=0;i<s.length();i++) {
            c[s[i]-'0'] ++;
        } 
        m[0] = c[0] + c[3] + c[6] + c[9];
        m[1] = c[1] + c[4] + c[7];
        m[2] = c[2] + c[5] + c[8];

        string ans = ""; int cnt = 0, lft = 0;
        for(int i=9;i>=0;i--) {
            if(i%3==0) {
                for( ; c[i]>0 && cnt<k ; ) {
                    if( lft!=0 && k-cnt==1 ) break;
                    ans += to_string(i);
                    c[i]--, cnt++ ;
                }
            } else if(i%3==2) {
                for( ; c[i]>0 && cnt<k ; ) {
                    if( lft == 0 ) {
                        if( m[1]==0 && m[2]<3 || k-cnt==1 ) break;
                    } else if( lft == 2 ) {
                        if( m[2]-1 == 0 || k-cnt==1 ) break;
                    }

                    lft += 2; lft %= 3;

                    ans += to_string(i);

                    c[i]--, cnt++, m[2]-- ;
                }
            } else if(i%3==1) {
                for( ; c[i]>0 && cnt<k ; ) {
                    if( lft == 0 ) {
                        if( m[2]==0 && m[1]<3 || k-cnt==1 ) break;
                    } else if( lft == 1 ) {
                        if( m[1]-1 == 0 || k-cnt==1 ) break;
                    }

                    lft += 1; lft %= 3;

                    ans += to_string(i);

                    c[i]--, cnt++, m[1]-- ;
                }
            }
        }

        while(ans[0]=='0') ans.erase(ans.begin());

        if(ans == "") {
            if(k==1) puts("0");
            else puts("-1");
        }
        else if(lft!=0||cnt!=k) puts("-1");
        else cout<<ans<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/