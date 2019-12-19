#include<iostream>
using namespace std;
const long long mod = 1e9+7;
long long fun[100010]; 
long long func(int x){
    if (fun[x]!=0){
        return fun[x];
    }
    else 
	return fun[x]=(x*func(x-1)+(x-1)*func(x-2))%mod;
}
int n;
int main(){
	fun[0]=1;fun[1]=1;
    cin>>n;
    cout<<func(n);
    return 0;
}
