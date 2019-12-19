#include <iostream>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		if(m%(n+1)==0) cout<<"You are loser"<<endl;
		else if(n>m){
			for(int i=m;i<=n;i++){
				cout<<i<<' ';
			}
			cout<<endl;
		}
		else cout<<m%(n+1)<<endl;
	}
}
