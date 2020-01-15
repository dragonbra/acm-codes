#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 3000010;
 
int main()
{
    int n,ans=0;
    cin>>n;
    while(n>1){
        if(n%2==1) n=n*3+1;
        else n/=2;
        ans++;
    }
    cout<<ans<<endl;
}
