#include<iostream>
using namespace std;

void Input(int a[],int n)            
{
    for(int i=0;i<n;i++)                
        cin>>a[i];
}

void Delete(int a[],int &n)            	
{
    int item;
    cin>>item;                          
    int num=0;                        	
    for(int i=0;i<n;i++)            	
    {
        if(a[i]!=item)                  
        {    
            a[num]=a[i];            	
            num++;                    	
        }
    }
    n=num;
}

void Output(int a[],int n)    
{
    for(int i=0;i<n-1;i++)                
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;                	
}

int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int a[100];
        Input(a,n);                	
        Delete(a,n);            	
        Output(a,n);            	
    }
    return 0;
}