#include <bits/stdc++.h>
using namespace std;

long long T,a,b,c,pp,mod;
long long n;

struct mat{
	long long m[4][4];
};

mat mul(mat a,mat b){
	mat ans;int i,j,k;
	for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            ans.m[i][j]=0;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            for(k=1;k<=3;k++)
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return ans;
}

mat matqp(mat t,long long p)
{
    mat ans;
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(i==j)ans.m[i][j]=1;
            else ans.m[i][j]=0;
    while(p)
    {
        if(p&1)
            ans=mul(ans,t);
        t=mul(t,t);
        p=p>>1;
    }
    return ans;
}

long long qp(long long a,long long p)
{
	long long ans=1;
	while(p){
		if(p&1) {ans*=a;ans%=pp;}
		a=a*a; a%=pp;
		p=p>>1;
	}
	return ans;
}

int main(){
	//scanf("%d",&T);
	cin>>T;
	while(T--)
	{
		//scanf("%I64d %d %d %d %d",&n,&a,&b,&c,&pp);
		cin>>n>>a>>b>>c>>pp;
		///*
		mod=pp-1;
		//*/
		mat base;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				base.m[i][j]=0;
		base.m[1][1]=c;base.m[1][2]=1;base.m[1][3]=1;base.m[2][1]=1;base.m[3][3]=1;
		if(n==1){
			cout<<1<<endl;
		}
		else{
			mat out = matqp(base,n-2);
			long long res = out.m[1][1]*b%mod + out.m[1][3]*b%mod;
			//cout<<res<<endl;
			long long ans = qp(a,res);
			cout<<ans<<endl;
		}
	}

	return 0;
}
