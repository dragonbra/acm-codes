#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 400000 + 10;
vector<int> edge[N];
bool vis[N]={0};
int f[N],in[N],surv[N],dele[N];
int ans[N];
int m,n,k,cnt,tot=0;

int getf(int x)
{
	if(f[x]==x) return x;
	else return f[x]=getf(f[x]);
}

void merge(int x,int y)
{
	int f1 = getf(x);
	int f2 = getf(y);
	if(f1==f2) return;
	else{
		f[f2]=f1;
		cnt++;
		return;
	}
}

int main()
{
	int i,j;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	for(i=0;i<n;i++) f[i]=i,in[N]=edge[i].size();
	
	cin>>k;
	for(i=1;i<=k;i++)
	{
		int d;
		cin>>d;
		vis[d]=1;
		dele[i]=d;
		for(j=0;j<edge[d].size();j++)
		{
			in[edge[d][j]]--;
		}
	}
	
	//for(i=1;i<=n;i++) cout<<vis[i]<<endl;
	int kk=0;
	//cout<<n<<endl;
	for(i=0;i<n;i++)
	{
		//cout<<i<<endl;
		if(vis[i]==0)
		{
			//cout<<i<<endl;
			kk++;
			surv[kk]=i;
			for(j=0;j<edge[i].size();j++)
			{
				if(vis[edge[i][j]]==0)	merge(i,edge[i][j]);
			}
			
		}
	}
	//for(i=1;i<=kk;i++) cout<<surv[i]<<endl;
	for(i=1;i<=kk;i++) if(f[surv[i]]==surv[i]) tot++;
	ans[k+1]=tot;
	for(i=k;i>=1;i--)
	{
		vis[dele[i]]=0;
		cnt=0;
		for(j=0;j<edge[dele[i]].size();j++)
		{
			//cout<<edge[dele[i]][j]<<endl; 
			if(vis[edge[dele[i]][j]]==0)
			{
				merge(dele[i],edge[dele[i]][j]);
			}
		}
		tot = tot - (cnt-1);
		ans[i]=tot;
	}
	for(i=1;i<=k+1;i++) cout<<ans[i]<<endl;
	
	return 0;
}