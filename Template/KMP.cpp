#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
char text[N],pattern[N];
int temp[N];

void build(){
	int n=strlen(pattern); temp[0]=0;
	for(int i=1,j=0;i<n;){
		if(pattern[i]==pattern[j]){
			temp[i]=j+1;
			i++;j++;
		}
		else if(j!=0){
			j=temp[j-1];
		}
		else if(j==0){
			temp[i]=0;i++;
		}
	}
}

int KMP(){//return where substring 'pattern' starts in string 'text'
	int n=strlen(text),m=strlen(pattern);
	for(int i=0,j=0;i<n;){
		if(text[i]==pattern[j]){
			if(j==m-1) return i-m+1;//matched and return the value
			else{
				i++;j++;
			}
		}
		else if(j!=0){
			j=temp[j-1];
		}
		else if(j==0){
			i++;
		}
	}
	return -1;
}

int main(){
	cin>>text>>pattern;
	build();
	for(int i=0;i<strlen(pattern);i++){
		cout<<temp[i]<<' ';
	}
	cout<<endl;
	cout<<KMP();
	return 0;
}

