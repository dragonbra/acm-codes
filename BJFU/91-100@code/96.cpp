#include<iostream>
using namespace std;
void Sort(int R1[],int R2[],int n)
{
	for(int i=0;i<n;i++)
	{	
		int num=0;
		for(int j=0;j<n;j++)
			if(R1[i]>R1[j])
				num++;
		R2[num]=R1[i];
	}
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int R1[100],R2[100];
        for(int i=0;i<n;i++)
            cin>>R1[i];
        Sort(R1,R2,n);
	for(int i=0;i<n-1;i++)
            cout<<R2[i]<<" ";
	cout<<R2[n-1]<<endl;
    }
}