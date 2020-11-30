#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int N=110;
const double EPS=1e-8;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,xx,yy;
double a[N][N],x[N];
void Gauss(int m,int n){
   for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(fabs(a[j][i])>1e-8){
                for(int k=1;k<=n;k++){
                    swap(a[i][k],a[j][k]);
                }
                swap(x[i],x[j]);
               }
        }
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double rate=a[j][i]/a[i][i];
            for(int k=i;k<=n;k++)a[j][k]-=a[i][k]*rate;
            x[j]-=x[i]*rate;
        }
    }
    x[1]=-xx;
    x[n]=yy;
    for(int i=n-1;i>=2;i--){
        for(int j=i+1;j<=n;j++)x[i]-=a[i][j]*x[j];
        x[i]=x[i]/a[i][i];
        if(fabs(x[i])<1e-8)x[i]=0;
    }
}//浮点数方程组
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&xx,&yy);
        memset(a,0,sizeof(a));
        memset(x,0,sizeof(x));
        a[1][1]=1;
        for(int i=2;i<n;i++){
            for(int j=1;j<=i;j++)
                a[i][j]+=1.0/2.0/(double)(i);
            a[i][i]-=1;
            for(int j=i;j<=n;j++)
                a[i][j]+=1.0/2.0/(double)(n-i+1);
        }
        a[n][n]=1;
        
        x[1]=-xx;
        x[n]=yy;
        Gauss(n,n);
        int q;
        scanf("%d",&q);
        while(q--){
            int pos;
            scanf("%d",&pos);
            printf("%.6lf\n",x[pos]);
        }
    }
    return 0;
}
