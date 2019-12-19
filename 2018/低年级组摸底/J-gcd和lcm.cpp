#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000010;
 
int gcd(int a,int b){
    if(b>a) swap(a,b);
    return a==b?a:gcd(b,a-b);
}
 
int main()
{
    int x,y;
    while(cin>>x>>y){
        int ans = gcd(x,y);
        cout<<ans<<endl<<x*y/ans<<endl;
    }
}
 
