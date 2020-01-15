#include <iostream>
#include <bits/stdc++.h>
#define maxn 5010
using namespace std;
int a[maxn],b[maxn];
 
int main()
{
    int n,l,r;
 
    memset(a,0,sizeof(a)); b[0]=0;
    for(int i=1;i<=5000;i++){
        if((i%4==0&&i%100!=0)||i%400==0) a[i]=1;
    }
    for(int i=1;i<=5000;i++){
        if(a[i]==1) b[i]=b[i-1]+1;
        else b[i]=b[i-1];
    }
 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",b[r]-b[l-1]);
    }
}
