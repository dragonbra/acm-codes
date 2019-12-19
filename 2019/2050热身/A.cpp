#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-3;
int T;int n,m,y;


int main(){
	ios::sync_with_stdio(false); 
	cin>>T;
	while(T--){
		cin>>n>>m>>y; int suma=0,sumb=0;double avea,aveb;
		int t;
		for(int i=1;i<=n;i++){
			cin>>t;suma+=t;
		}
		for(int i=1;i<=m;i++){
			cin>>t;sumb+=t;
		}
		avea = 1.0*suma/n;
		aveb = 1.0*sumb/m;
		double p1 = 1.0*n/(n+m),p2 = 1.0*m/(n+m);
		double curp = p1,cur=avea*p1;double acc=cur;double sum=avea;
		while(cur>eps){
			curp *= p2; sum += aveb; cur = curp*sum; acc += cur;
		}
		
		//cout<<endl<<avea<<' '<<aveb<<" p "<<p1<<' '<<p2<<' '<<acc<<endl;
		
		if(acc>y) cout<<"Wait"<<endl;
		else cout<<"Go"<<endl;
	}
	
	return 0;
}
