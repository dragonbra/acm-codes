#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if((i%4==0&&i%100!=0)||i%400==0) cout<<i<<endl;
    }
}
