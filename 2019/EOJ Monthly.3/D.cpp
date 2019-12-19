#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,x1,y1,x2,y2;
	cin>>n>>m;cin>>x1>>y1>>x2>>y2;
	int cmp = abs(x1-x2)+abs(y1-y2);
	if(cmp%2==0) cout<<"Win"<<endl;
	else cout<<"Lose"<<endl;
	return 0;
}
