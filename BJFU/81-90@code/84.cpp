#include<iostream>
using namespace std;
#define MAX 200
void Find(int a[],int k,int low,int high)
{
	if(low>high)
	{
		cout<<"NO"<<endl;
		return;
	}
	int mid=(low+high)/2;
	if(a[mid]==k)
	{
		cout<<"YES"<<endl;
		return;
	}
	else
	{
		if(k<a[mid])
			Find(a,k,low,mid-1);
		else
			Find(a,k,mid+1,high);
	}
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int a[MAX],k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cin>>k;
		Find(a,k,1,n);
	}
	return 0;
}
