#include <bits/stdc++.h>
using namespace std;
//ascii 32-126 kedayin 
int is[257],vis[257];
char s[100010];
bool iss[100010]; 

int main(){
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++){
		is[s[i]]=1;
	}
	
	int wait[100];int cnt=0;
	for(int i=0;i<=256;i++){
		if(is[i]==1){
			wait[++cnt]=i;
		}
	}
	
	int hmk=1,tmk=cnt;
	//printf("%c\n",33);
	/* 
	int lpos=0,rpos=len-1; 
	while(hmk<=tmk){
		for(int i=lpos;i<len;i++){
			if(s[i]==wait[hmk]){
				iss[i]=1;lpos=i;hmk++;break;//vis[s[i]]=1;
			}
		}
		if(hmk>tmk) break;
		for(int i=rpos;i>=0;i--){
			if(s[i]==wait[tmk]){
				iss[i]=1;rpos=i;tmk--;break;
			}
		}
		if(hmk>tmk) break;
	}
	*/
	///*
	int pos=0;int lpos=0; 
	for(int i=0;i<len;i++){
		if(s[i]==wait[hmk]){
			iss[i]=1;pos=i;hmk++;break;
		}
	}
	while(hmk<=tmk){
		int flag=0;
		
		for(int i=pos+1;i<len;i++){
			if(s[i]==wait[hmk]){
				iss[i]=1;pos=i;hmk++;flag=1;break;
			}
		}
		
		if(!flag){
			for(int i=lpos;i<pos;i++){
				if(s[i]==wait[hmk]){
					iss[i]=1;lpos=i;hmk++;flag=1;break;
				}
			}
		}
		
		if(!flag){
			for(int i=0;i<lpos;i++){
				if(s[i]==wait[hmk]){
					iss[i]=1;hmk++;break;
				}
			}
		}
	}
	//*/
	//EFDBDFECDBACEC
	//for(int i=0;i<len;i++) cout<<iss[i];
	for(int i=0;i<len;i++){
		if(iss[i]==1) printf("%c",s[i]);
	}
	
	return 0;
}
