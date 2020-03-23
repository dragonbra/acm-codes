#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{	
      	int a[101];
		for(int i=1;i<=n;i++) cin>>a[i];

		int cnt = 0;

		for(int i=1;i<=n;i++){
			if(a[i]>0) {
				cout<<a[i],cnt++;
				if(cnt!=n) cout<<' ';
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]<0) {
				cout<<a[i],cnt++;
				if(cnt!=n) cout<<' ';
			}
		}

		cout<<endl;
	}
	return 0;
}
