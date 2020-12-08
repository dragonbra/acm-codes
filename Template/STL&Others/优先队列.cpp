#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int tmp[100];
struct cmp1{
	bool operator()(int x,int y)
	{
		return x>y;//小的优先级高 ,从小到大排 
	}
}; 
struct cmp2{
	bool operator()(const int x,const int y)
	{
		return tmp[x]>tmp[y];
	}
}; 
struct node{
	int x,y;
	friend bool operator<(node a,node b)
	{
		return a.x>b.x;//按x从小到大排 
	}
};
priority_queue<int>q1;
priority_queue<int,vector<int>,cmp1>q2;
priority_queue<int,vector<int>,cmp2>q3;
priority_queue<node>q4;
int main()
{
	int i,j,k,m,n;
	int x,y;
	node a;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a.y>>a.x;
			q4.push(a);
		}
		cout<<endl;
		while(!q4.empty())
		{
			cout<<q4.top().y<<" "<<q4.top().x<<" "<<endl;
			q4.pop();
		}
		cout<<endl;
		
	int t;
		for(i=0;i<n;i++)
		{
			cin>>t;
			q2.push(t);
		}
		while(!q2.empty())
		{
			cout<<q2.top()<<endl;
			q2.pop();
		}
		cout<<endl;
	}
	return 0;
}