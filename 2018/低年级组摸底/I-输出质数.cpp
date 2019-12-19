#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 3000010;
 
int main()
{
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
 
        int cmp=floor(sqrt(i));int flag=0;
 
        for(int j=2;j<=cmp;j++){
            if(i%j==0){flag=1;break;}
        }
 
        if(i==1) flag=1;
        if(!flag) cout<<i<<endl;
    }
}
