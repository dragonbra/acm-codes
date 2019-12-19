#include   <iostream>
#include    <cstring>
#include     <cstdio>
#include      <queue>
#include        <map>
#include      <cmath>
#include     <vector>
#include  <algorithm>
#include        <set>
#include      <stack>
#include    <climits>

#define mem(x,y) memset(x,y,sizeof(x))
#define INF   1e9
#define EPS   1e-6
#define MOD   1000000007
#define PI    3.141592654

typedef long long ll;

struct Point
{
	int x,y;
}save[1010];

int ans[1010];

int n,pos;

bool vis[1010];

int dis(Point a,Point b)
{
	int disx=a.x-b.x;
	int disy=a.y-b.y;
	return disx*disx+disy*disy;
}

int CrossProduct(Point a,Point b,Point c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

using namespace std;


int main()
{
    //freopen("10.in", "r", stdin);
    //freopen("10.out", "w", stdout);
    int n;
    scanf("%d",&n);
    pos=1;
	for(int i=1;i<=n;i++)
    {
    	scanf("%d %d",&save[i].x,&save[i].y);
    	if(save[i].y<save[pos].y) pos=i;
	}
	mem(vis,false);
	vis[pos]=true;
	ans[1]=pos;
	int temp;
	int tp;
	for(int i=2;i<=n;i++)
	{
		temp=1;
		while(vis[temp]) temp++;
		tp=temp+1;
		while(tp<=n)
		{
			if(!vis[tp])
			{
				int t=CrossProduct(save[tp],save[temp],save[ans[i-1]]);
				if(t>0||(t==0&&(dis(save[tp],save[ans[i-1]])<dis(save[temp],save[ans[i-1]])))) temp=tp;
			}
			tp++;
		}
		vis[temp]=true;
		ans[i]=temp;
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		printf("%d%c",ans[i],i==n?'\n':' ');
	}
    //fclose(stdin);
    //fclose(stdout);
}
