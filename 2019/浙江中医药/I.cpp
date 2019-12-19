#include <iostream>
#include <cstring>
using namespace std;
char a[1010][1010];
bool check(int i,int x){
	if(a[i][x]=='z'&&a[i][x+1]=='a'&&a[i][x+2]=='i'
	&&a[i][x+3]=='l'&&a[i][x+4]=='a'&&a[i][x+5]=='i'
	&&a[i][x+6]=='y'&&a[i][x+7]=='i'&&a[i][x+8]=='h'
	&&a[i][x+9]=='e') return true;
	else return false;
}

int main(){
	int n;int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int len = strlen(a[i]);
		for(int j=0;j<len;j++){
			if(a[i][j]=='z'&&check(i,j)){
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
