#include <bits/stdc++.h>
using namespace std;

int main(){
	int s1,s2,s3;
	int a[101];memset(a,0,sizeof(a));
	cin>>s1>>s2>>s3;
	
	for(int i=1;i<=s1;i++){
		for(int j=1;j<=s2;j++){
			for(int k=1;k<=s3;k++){
				a[i+j+k]++;
			}
		}
	}
	
	int end=s1+s2+s3;int mark=1,cmp=0;
	for(int i=1;i<=end;i++){
		mark = a[i]>cmp ? i:mark;
		cmp = a[i]>cmp ? a[i]:cmp;
	}
	cout<<mark<<endl; 
}
