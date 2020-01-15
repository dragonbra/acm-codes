#include <bits/stdc++.h>
using namespace std;

char name[102][11];int arr[101];

bool cmp(int a,int b){
	return strcmp(name[a],name[b]) < 0;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	 
	int n=1;
	while(scanf("%s",name[n])!=EOF){
		arr[n]=n;n++;
	}n--;
	sort(arr+1,arr+n+1,cmp);
	
	int mark=1;int count=0;
	for(int i=1;i<=n+1;i++){
		if(strcmp(name[arr[i]],name[arr[mark]])==0) count++;
		else{
			cout<<name[arr[mark]]<<' '<<count<<endl;count=1;mark=i;
		} 
	}
	
	//for(int i=1;i<=n;i++) cout<<t[i]<<endl;
}
