#include <iostream>
using namespace std;

int a[101][101];

int main(){
	for(int i=1;i<=15;i++){
		a[i][1]=a[i][i]=1;
	}
	for(int i=1;i<=15;i++){
		for(int j=1;j<=i;j++){
			if(!a[i][j]){
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
	}
	int n;
	cin>>n;
	for(int i=n+1,j=1;j<=i;j++){
		cout<<a[i][j]<<' ';
	}
	cout<<endl;
}
