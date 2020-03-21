#include<iostream>
using namespace std;

void Input(int R[],int n)    
{
    for(int i=0;i<n;i++)                
        cin>>R[i];
}

void FindMid(int A[],int B[],int n)            	
{
    int s1=0,e1=n-1,s2=0,e2=n-1;
    while(s1<e1&&s2<e2)
    {
        int mid1=(s1+e1)/2;
        int mid2=(s2+e2)/2;
        if(A[mid1]==B[mid2])			
        {
            cout<<A[mid1]<<endl;
            return;
        }
        if(A[mid1]<B[mid2])			
        {
            if((e1-s1)%2==0)    		
                s1=mid1;
            else
                s1=mid1+1;
            e2=mid2;
        }
        else                    		
        {
            if((e2-s2)%2==0)    		
                s2=mid2;
            else
                s2=mid2+1;
            e1=mid1;
        }
    }
    if(A[s1]<B[s2])               		
        cout<<A[s1]<<endl;
    else 
        cout<<B[s2]<<endl;
}

int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int A[100];
        int B[100];
        Input(A,n);                		
        Input(B,n);                		
        FindMid(A,B,n);            		
    }
    return 0;
}