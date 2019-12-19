#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
using namespace std;
int n,a[100],minx,sum,ans;
int main(){
    freopen("1.txt","r",stdin);
    freopen("21.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            sum=0,minx=0x3f3f3f;
            for(int k=i;k<=j;k++)minx=min(minx,a[k]),sum+=a[k];
            if(sum*minx>ans)ans=sum*minx;
        }
    printf("%d\n",ans);
    return 0;
}

