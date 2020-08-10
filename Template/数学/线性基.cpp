#include <bits/stdc++.h>
#define N 51
#define ll long long
using namespace std;

//给n个数，输出n个数里异或和的最大值

int n;
ll ans;
ll a[N], p[101];

inline ll read()
{
    char ch = getchar();
	ll x = 0, f = 1;
    while(ch > '9' || ch < '0')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
    while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}

void Get_LB(ll x)
{
	for(int i = 62; i >= 0; i--)
	{
		if(!(x >> (ll)i))
			continue;
		if(!p[i])
		{
			p[i] = x;
			break;
		}
		x ^= p[i];
	}
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i++)
		Get_LB(a[i] = read());
	for(int i = 62; i >= 0; i--)
		if((ans ^ p[i]) > ans)
			ans ^= p[i];
	cout << ans;
	
	 return 0;
}