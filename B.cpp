//#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast","inline","-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<cassert>
#include<bitset>
using namespace std;
     
typedef long long LL;
     
typedef unsigned long long ull;
     
const int inf=0x3f3f3f3f;
 
const int N=1e6+100;
 
char s[N];
 
int n;
 
vector<int>node1,node2;
 
bool check(int mid)
{
	if(node1.size()<mid*2)
		return false;
	for(int i=0;i<mid;i++)
		if(node1[i]>node2[mid-i-1])
			return false;
	return true;
}
 
void init()
{
	node1.clear(),node2.clear();
	int pos=1;
	for(int i=1;i<=n;i++)
		if(s[i]=='0')
		{
			while(pos<i&&s[pos]!='2')
				pos++;
			if(pos==i)
				continue;
			pos++;
			node1.push_back(i); 
		}
	pos=n;
	for(int i=n;i>=1;i--)
		if(s[i]=='2')
		{
			while(pos>i&&s[pos]!='0')
				pos--;
			if(pos==i)
				continue;
			pos--;
			node2.push_back(i);
		}

    
    // cout << "--------" << endl;
    // for (int x : node1) cout << x - 1 << ' '; cout << endl;
    // for (int x : node2) cout << x - 1 << ' '; cout << endl;
    // cout << "--------" << endl;
}
 
int main()
{
#ifndef ONLINE_JUDGE
//  freopen("data.in.txt","r",stdin);
//  freopen("data.out.txt","w",stdout);
#endif
//  ios::sync_with_stdio(false);
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",s+1);
		init();
		int l=0,r=inf,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		printf("%d\n",ans);
	}

    return 0;
}