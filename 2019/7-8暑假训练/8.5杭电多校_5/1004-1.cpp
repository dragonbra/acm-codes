#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;

int T,n;ll c;
ll gcd(int a,int b) {if(a<0) a=-a;if(b<0) b=-b;if(a<b)swap(a,b);return b?gcd(b,a%b):a;}

struct node{
    ll a,b;// =b/a;
    double v;
    
    void print(){
        if(a<0){
            a=-a;b=-b;
        }
        ll g=gcd(a,b);
        a=a/g;b=b/g;
        if(a==0&&b==0){
            printf("0/1 ");
        }
        else cout<<b<<'/'<<a<<' ';
    }
} E[N],F[N],ans[N];
ll Pa[N],Pb[N];

bool cmp(node a,node b){
    return a.v<b.v;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&c);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&E[i].a,&E[i].b);
            E[i].v=-1.0*E[i].b/E[i].a;
        }
        sort(E+1,E+n+1,cmp);
        
        int m=0;
        for(int i=1;i<=n;i++){
            if(i<n&&E[i].v==E[i+1].v){
                E[i].a+=E[i+1].a;E[i].b+=E[i+1].b; 
                F[++m]=E[i];i++;
            }
            else F[++m]=E[i];
        }
        
        Pa[0]=Pb[0]=0;
        for(int i=1;i<=m;i++){
            Pa[i]=Pa[i-1]+F[i].a;
            Pb[i]=Pb[i-1]+F[i].b;
        }
        
        bool inf_flag=false;int cnt=0;
        for(int i=1;i<=m+1;i++){
            ll A = Pa[i-1]+Pa[i-1]-Pa[n];
            ll B = Pb[i-1]+Pb[i-1]-Pb[n];
            if(A==0){
                if(B==c){
                    inf_flag=true;
                    break;
                }
                continue;
            }
            node sol; sol.b=c-B,sol.a=A, sol.v=1.0*sol.b/sol.a;
            //cout<<F[i-1].v<<' '<<sol.v<<' '<<F[i].v<<endl;
            if((i==1||F[i-1].v<sol.v)&&(i==m+1||sol.v<=F[i].v)){
                ans[++cnt]=sol;
            }
        }
        
        //cout<<endl;
        if(inf_flag){
            printf("-1");
        }
        else{
            printf("%d ",cnt);
            for(int i=1;i<=cnt;i++) ans[i].print();
        }
        printf("\n");
        //cout<<endl;
        
    }
    return 0;
}
