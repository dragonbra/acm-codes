#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,k;
char s[maxn];
bool check(int n,int x){
	for(int i=0;i<n;i++)
		if(i+x<n){
			if(s[i]==s[i+x])continue;
			return false;
		}
	return true;
}

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int main(){
    redirect();
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",&s); 
	if(check(n,k))printf("%d\n%s\n",n,s);
	else{
		printf("%d\n",n); 
		for(int i=0;i<k;i++){
			int flag=1;
			for(int j=i+k;j<n;j+=k)
				if(s[j]==s[i])continue;
				else if(s[j]<s[i]){flag=2;break;}else{flag=0;break;}
			//if(flag==2)break;
			if(!flag){
				s[k-1]++;
				break;
			}
		}
		int flag=0;
		while(!flag){
			flag=1;
			for(int i=k-1;i>=1;i--)
				if(s[i]==':')s[i]='0',s[i-1]++,flag=0;
		}
		int cnt=0;
		for(int i=0;i<k;i++)
			for(int j=i;j<n;j+=k)s[j]=s[i];
		printf("%s\n",s);
	}
	return 0;
}