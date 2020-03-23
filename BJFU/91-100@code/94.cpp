#include<iostream>
using namespace std;
void Divide(int R[],int n)
{
	int low=0;
	int high=n-1;
	int temp;
	while(low<high)
	{
		while(low<high&&R[high]>=0)
			high--; 
		while(low<high&&R[low]<0)
			low++;
			temp=R[low];
			R[low]=R[high];
			R[high]=temp;
	}
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int R[100];
        for(int i=0;i<n;i++)
            cin>>R[i];
        Divide(R,n);
		for(int i=0;i<n-1;i++)
            cout<<R[i]<<" ";
		cout<<R[n-1]<<endl;
	}
}
