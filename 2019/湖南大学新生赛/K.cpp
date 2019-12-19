#include <bits/stdc++.h>
using namespace std;

const int maxn = 45001;   // 表长
int prime[maxn], pNum = 0;  // prime存放素数，pNum为素数个数
bool p[maxn] = {false};     // 标记，素数false，合数true

void eratosthenesSieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == false)      // 如果i是素数
        {
            if(i%4==1) prime[++pNum] = i;  // 记录i
            for (int j = i + i; j <= n; j += i)     // 筛去所有i的倍数
                p[j] = true;
        }
    }
}

int main(){
	
	int t;
	cin>>t;
	eratosthenesSieve(45001);
	
	for(int i=1;i<=t;i++){
		int m;int flag=0;
		cin>>m;
		for(int j=1;j<=pNum;j++){
			//cout<<prime[j]<<endl;
			if(m%prime[j]==0){
				flag=1;break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
