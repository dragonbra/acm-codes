#include <bits/stdc++.h>
using namespace std;

char a[10010];

bool is_Alice(int p){
	if(a[p]=='A'&&a[p+1]=='L'&&a[p+2]=='I'&&a[p+3]=='C'&&a[p+4]=='E') return true;
	else return false;
}

bool is_Bob(int p){
	if(a[p]=='B'&&a[p+1]=='O'&&a[p+2]=='B') return true;
	else return false;
}

int main()
{
	while(cin>>a)
	{
		int len = strlen(a); int A_1=10000,B_1=10000, A_2=-1,B_2=-1;
		for(int i=0;i<len;i++){
			if(is_Alice(i)) A_1=min(i,A_1),A_2=max(i,A_2);
			if(is_Bob(i)) B_1=min(i,B_1),B_2=max(i,B_2);
		}
		if(A_2==-1||B_2==-1) cout<<"-1"<<endl; 
		else cout<<max(B_2-A_1-5,A_2-B_1-3)<<endl;
	}
	return 0;
}
