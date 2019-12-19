#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;x=x+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main()
{
	int n=read();int a=0,b;int ans=0;
	for(int i=1;i<=n;i++){
		b=read();
		ans+=b>a?b-a:0;
		a=b;
	}
	cout<<ans<<endl;
}
