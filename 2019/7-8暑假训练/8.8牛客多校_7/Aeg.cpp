#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("in.txt","w",stdout);
	
	srand(clock());
	int T= rand();
	cout<<T<<endl;
	while(T--){
		int t=rand()%100;
		for(int i=1;i<=t;i++){
			int tt=rand()%2;
			if(tt) cout<<'1';
			else cout<<'0';
		}
		cout<<endl;
	} 
	return 0;
}

