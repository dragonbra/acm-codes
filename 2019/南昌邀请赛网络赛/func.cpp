int gcd(int a,int b){
	if(a>b) swap(a,b);
	return a==0?b:gcd(b-a,a);
}

inline int read(){
	int x=0,f=1;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		x*=10;x=x+t-'0';
		t=getchar();
	}
	return x*f;
}

ll qp(ll x,ll n){
	ll res = 1;
	while(n){
		if(n&1) res*=x,res%=mod;
		x*=x;x%=mod;
		n>>=1;
	}
	return res;
}
