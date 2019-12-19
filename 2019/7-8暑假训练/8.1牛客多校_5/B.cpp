#include<bits/stdc++.h>
using namespace std;
struct arr{
    long long a[2][2];
}con;
const int N = 1e6+10;
char n[N];
long long x0,x1,a,b,c,p;//p=mod

long long quick(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}

arr matrix(arr x,arr y){
	arr mp;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            mp.a[i][j]=0;
            for(int k=0;k<2;k++)
                mp.a[i][j]=(mp.a[i][j]+x.a[i][k]*y.a[k][j])%(p);
        }
    return mp;
}
arr matrix_pow(arr t,long long k){
	arr res={1,0,0,1};
    while(k){
        if(k&1)res=matrix(res,t);
        k>>=1;
        t=matrix(t,t);
    }
    return res;
}

long long work(int pt){
	arr res={a*x1+b*x0,x1,x1,x0};
	while(pt>=0){
		if(n[pt]-'0'){
			int num=n[pt]-'0';
			res=matrix(res,matrix_pow(con,num));
		}
		con=matrix_pow(con,10);
		pt-=1;
	}
	return res.a[1][1];
}

int main(){
    scanf("%lld %lld %lld %lld",&x0,&x1,&a,&b);
    con={a,1,b,0};
    
    scanf("%s %lld",&n,&p);//p=mod;
    int len = strlen(n);
	printf("%lld\n",work(len-1));
    return 0;
}
