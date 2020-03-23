#include<iostream>
using namespace std;
bool map[1000][1000]; 
bool book[1000];
 
bool search(int a,int b) { 
	book[a]=true;
	if(map[a][b]) {
		return true;
	}
	bool hasroad=false;
	for(int i=0; i<1000; i++) {
		
		if(map[a][i]&&!book[i]){
			hasroad=(hasroad||search(i,b));
		}
	}
	return hasroad;
}
 
int main() {
	int n,m;
	while(cin>>n>>m&&(n||m)) {
		
		for(int i=0; i<1000; i++) {
			book[i]=false; 
			for(int j=0; j<1000; j++) {
				map[i][j]=false;
			}
		}
		
		char t;
		for(int i=0; i<n; i++) {
			cin>>t;
		}
		for(int i=0; i<m; i++) {
			char a,b;
			cin>>a>>b;
			map[(int)a][(int)b]=map[(int)b][(int)a]=true;
		}
		char searcha,searchb;
		cin>>searcha>>searchb;
		if(search((int)searcha,(int)searchb)) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
 
 
	return 0;
}