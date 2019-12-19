#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[27];int f[maxn][27];
char s[maxn],t[maxn];int n;

int main(){
	while(~scanf("%s",s)){
		
		int len = strlen(s);
		//for(int i=1;i<=26;i++) cout<<a[i]<<' ';cout<<endl;
		
		memset(a,0,sizeof(a));
		for(int i=len-1;i>=0;i--){
			for(int j=1;j<=26;j++){
				f[i][j]=a[j];
			}
			a[s[i]-'a'+1]=i+1;
		}
		//for(int i=1;i<=26;i++) f[0][i]=a[i];
		/*
		for(int i=1;i<=26;i++) cout<<a[i]<<' ';cout<<endl;
		for(int i=1;i<=26;i++){
			for(int j=0;j<len;j++) cout<<f[j][i]<<' ';
			cout<<endl;
		}
		*/
		
		scanf("%d",&n);
		while(n--){
			scanf("%s",t);
			int len2 = strlen(t);int pter=a[t[0]-'a'+1]-1;bool flag = true;
			for(int i=0;i<len2;i++){
				//cout<<pter<<endl;
				if(pter==-1) flag = false;
				pter=f[pter][t[i+1]-'a'+1]-1;
			}
			if(flag) printf("YES\n");
			else printf("NO\n");
		}
		
		
	}
	return 0;
}
