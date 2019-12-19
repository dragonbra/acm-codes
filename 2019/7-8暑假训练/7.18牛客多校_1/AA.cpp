#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int A[N],B[N];
vector <int> qa,qb; 
int n;

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&B[i]);
		int ans=1;qa.clear();qb.clear();
		
		for(int i=1;i<=n;i++){
			if(qa.empty())
				qa.push_back(A[i]);
			else if(qa.back()>A[i]){
				while((!qa.empty())&&qa.back()>A[i]){
					qa.pop_back();
				}
				qa.push_back(A[i]);
			}
			else
				qa.push_back(A[i]);
				
			if(qb.empty())
				qb.push_back(B[i]);
			else if(qb.back()>B[i]){
				while((!qb.empty())&&qb.back()>B[i]){
					qb.pop_back();
				}
				qb.push_back(B[i]);
			}
			else
				qb.push_back(B[i]);
				
			//cout<<qa.size()<<' '<<qb.size()<<endl;
			if(qa.size()!=qb.size()){
				ans=i-1;break;
			}
			else if(i==n) ans=n;
		} 
		printf("%d\n",ans);
	}
	return 0;
}
