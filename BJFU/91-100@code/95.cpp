#include<iostream>
using namespace std;
int Search(int r[],int low,int high,int key)
{
    while(low<high)
    {
        if(r[low]>key&&r[high]<key)
        {
            high--;
			low++;
        }
		while(low<=high&&r[high]>key)
			high--;
		if(r[high]==key)
			return high;
		while(low<=high&&r[low]<key)
			low++;
		if(r[low]==key)
			return low;
	}
    cout<<"not find"<<endl;
	return 0;
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int r[100],key;
        for(int i=0;i<n;i++)
            cin>>r[i];
        cin>>key;
        if(Search(r,0,n,key))
			cout<<Search(r,0,n,key)+1<<" "<<key<<endl;
    }
}
