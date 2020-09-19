#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100001];
vector<int>p,q;
int main(){
	int ans1=0,ans2=0;
	ios::sync_with_stdio(false);
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int t=n,h=n/2;
		for(int i=1;i<=n;i++){
			if(i%2)p.push_back(a[t--]);
			else p.push_back(a[h--]);
		}
		for(int i=1;i<n-1;i+=2)if(p[i]<p[i+1]&&p[i]<p[i-1])ans1++;
		t=n,h=1;
				for(int i=1;i<=n;i++){
			if(i%2)q.push_back(a[t--]);
			else q.push_back(a[h++]);
		}
		for(int i=1;i<n-1;i+=2)if(q[i]<q[i+1]&&q[i]<q[i-1])ans2++;
		if(ans1>ans2){
			cout<<ans1<<endl;
		for(int i=0;i<n;i++)cout<<p[i]<<" ";}
		else{
			cout<<ans2<<endl;
			for(int i=0;i<n;i++)cout<<q[i]<<" ";
		} 
		cout<<endl;	
}