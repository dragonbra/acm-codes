#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,m,k,cnt,len,sum,num;
char s[3*N];
int a[N*24],b[10],ans[4*N],f[8];
int main(){
    scanf("%s",&s);
    len=strlen(s);
    num=-1;f[5]=1;
    for(int i=4;i>=0;i--)f[i]=f[i+1]*2;
    for(int i=0;i<len;i++){
        sum=s[i];cnt=-1;
        while(sum>0){
            b[++cnt]=sum%2;
            sum/=2;
        }
        for(int j=0;j<8;j++)a[++num]=b[j];
    }
    /*for(int i=0;i<6;i++)printf("%d ",f[i]);
    for(int i=0;i<num;i++)printf("%d",a[i]);*/
    sum=0;
    for(int i=0;i<num;i+=6){
        sum++;
        for(int j=0;j<6;j++)
            ans[sum]+=a[i+j]*f[j];
    }
    for(int i=1;i<=sum;i++){
    	printf("%d ",ans[i]);
	}
    return 0;
}

