#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[210];
int T;int cnt,ans;
int a[210],b[210],l[210];

int main(){
	scanf("%d",&T);
	while(T--){
		cnt=0,ans=0;
		scanf("%s",s);
		
		int len=strlen(s);
		if(s[len-1]=='0'){
			ans++;
			while(s[len-1]=='0') len--;
		}
		
		int t=-1,lth,ll;bool vis=0;
		for(int i=0;i<len;i++){
		    if(s[i]=='1'&&!vis) { ll=i-t;vis=1; }//a-第一个1在这个子串中出现的位置 b-pos
			if( s[i]=='1' && (i==len-1||s[i+1]=='0') ){
				a[++cnt]=ll; b[cnt]=i; l[cnt]=i-t; t=i;vis=0;
			}
		}
		/*
		for(int i=1;i<=cnt;i++) cout<<a[i]<<' ';cout<<endl;
		for(int i=1;i<=cnt;i++) cout<<b[i]<<' ';cout<<endl;
		for(int i=1;i<=cnt;i++) cout<<l[i]<<' ';cout<<endl;
		//*/
		len=strlen(s);int now=1,mk=a[1],lmk=0,scd=0;
		for(int i=0;i<len;){
			if(now>cnt){
				while(i<len){
					printf("%c",s[i]);i++;
				}
				break;
			}
			while(i<=b[now]){
				printf("%c",s[i]);i++;
			}
			
			if( scd==0 ) scd=a[now+1];
			if( a[now]==mk ) lmk=max(lmk,l[now]);
			
			if( ( a[now+1]==mk && scd!=0 && mk>scd ) || ( a[now+1]==mk && l[now+1]<lmk ) || a[now+1]>mk || now==cnt){
				printf(" ");
				scd=0;lmk=l[now+1];mk=a[now+1];
			}
			now++;
		}
		printf("\n");
		
	}
	
	return 0;
}

