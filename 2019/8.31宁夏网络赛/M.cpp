#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}


const db PI=acos(-1.0);
struct Complex
{
    db x,y;
    Complex(db _x=0,db _y=0):x(_x),y(_y){}
    Complex operator + (const Complex &t)const
    {
        return Complex(x+t.x,y+t.y);
    }
    Complex operator - (const Complex &t)const
    {
        return Complex(x-t.x,y-t.y);
    }
    Complex operator * (const Complex &t)const
    {
        return Complex(x*t.x-y*t.y,x*t.y+y*t.x);
    }
    Complex operator / (const db &t)const
    {
        return Complex(x/t,y/t);
    }
};

namespace FFT
{
const int MAXN=1<<18;
void change(Complex y[],int len)
{
    for(int i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k)j-=k,k/=2;
        if(j<k)j+=k;
    }
}
Complex pmr[MAXN+1];
void init()
{
    for(int i=0;i<=MAXN;i++)
        pmr[i]=Complex(cos(2*PI*i/MAXN),sin(2*PI*i/MAXN));
}
void fft(Complex a[],int len,int on)
{
    change(a,len);
    for(int h=2;h<=len;h<<=1)
        for(int j=0,s=MAXN/h;j<len;j+=h)
            for(int k=j,t=0;k<j+h/2;k++,t+=s)
            {
                Complex w=pmr[(on>0 ? t : MAXN-t)];
                Complex u=a[k],v=w*a[k+h/2];
                a[k]=u+v,a[k+h/2]=u-v;
            }
    if(on==-1)for(int i=0;i<len;i++)
        a[i]=a[i]/len;
}
}

const int MAXN=60005;
const int MAXL=1<<18;

ll Mod,Sqt;

Complex p[3][MAXL],q[2][MAXL];
void poly_mul(ll f[],ll g[],int len)
{
    for(int i=0;i<len;i++)
    {
        p[0][i]=f[i]/Sqt,p[1][i]=f[i]%Sqt;
        q[0][i]=g[i]/Sqt,q[1][i]=g[i]%Sqt;
    }
    for(int i=0;i<2;i++)
        FFT::fft(p[i],len,1),FFT::fft(q[i],len,1);
    for(int i=0;i<len;i++)
    {
        p[2][i]=p[0][i]*q[1][i]+p[1][i]*q[0][i];
        p[0][i]=p[0][i]*q[0][i],p[1][i]=p[1][i]*q[1][i];
    }
    for(int i=0;i<3;i++)
        FFT::fft(p[i],len,-1);
    for(int i=0;i<len;i++)
    {
        ll tmp[3];
        for(int j=0;j<3;j++)
            tmp[j]=(ll)(p[j][i].x+0.5)%Mod;
        f[i]=(tmp[0]*Sqt*Sqt+tmp[1]+tmp[2]*Sqt)%Mod;
    }
}

ll fast_pow(ll a,ll k)
{
    if(k<0)a=fast_pow(a,Mod-2),k=-k;
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}

ll poly_f[MAXL],poly_g[MAXL];

ll Fac[MAXN*2],Inv[MAXN*2],Sti[MAXN],Pre[MAXN];
void get_stirling(int n)
{
    int len=1;
    while(len<=2*n)len<<=1;
    for(int i=0;i<len;i++)
    {
        poly_f[i]=(i<=n ? fast_pow(Mod-1,i)*Inv[i]%Mod : 0);
        poly_g[i]=(i<=n ? fast_pow(i,n)*Inv[i]%Mod : 0);
    }
    poly_mul(poly_f,poly_g,len);
    for(int i=0;i<=n;i++)
        Sti[i]=poly_f[i];
}
ll get_answer(int n,int m)
{
    int len=1;
    while(len<=n+m)len<<=1;
    for(int i=0;i<len;i++)
    {
        poly_f[i]=(i<=n ? Pre[i] : 0);
        poly_g[i]=(i<=m ? Sti[i] : 0);
    }
    poly_mul(poly_f,poly_g,len);
    for(int i=0;i<=n+m;i++)
        poly_f[i]=poly_f[i]*Fac[i]%Mod;
    ll res=0;
    for(int i=0,j=1;i<=n+m;i++,j=-j)
        res=(res+j*poly_f[i])%Mod;
    if((n+m)&1)res=-res;
    return (res+Mod)%Mod;
}

ll solve(int n,int m)
{
    for(int i=(Fac[0]=1);i<=n+m+1;i++)
        Fac[i]=i*Fac[i-1]%Mod;
    Inv[n+m+1]=fast_pow(Fac[n+m+1],-1);
    for(int i=n+m;i>=0;i--)
        Inv[i]=(i+1)*Inv[i+1]%Mod;
    get_stirling(n);
    for(int i=0;i<=n;i++)
        Pre[i]=Sti[i];
    get_stirling(m);
    return get_answer(n,m);
}

int main()
{
	redirect();
    FFT::init();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,m;
        scanf("%d%d%lld",&n,&m,&Mod);
        Sqt=sqrt(Mod);
        printf("Case #%d: %lld\n",ca,solve(n,m));
    }
    return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

