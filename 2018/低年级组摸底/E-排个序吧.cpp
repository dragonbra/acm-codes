#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 110;
int a[maxn];
 
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }
}
