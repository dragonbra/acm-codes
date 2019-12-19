#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1200000;  //�ַ��ܳ��ȼ��������ַ��ĸ���
int n,num;
int s[maxn],t1[maxn],t2[maxn],rk[maxn],c[maxn],height[maxn],sa[maxn],dp[maxn][25];
char str1[maxn];
int lens[maxn],belong[maxn];
int len;
int cmp(int *r,int a,int b,int k)
{
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void build_sa(int n,int m)
{
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++)c[i]=0;
    for(int i=0;i<n;i++)c[x[i]=s[i]]++;
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    int p;
    for(int k=1;k<=n;k<<=1,m=p)
    {
        p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[y[i]]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for(int i=1;i<n;i++)
        {
            x[sa[i]]=cmp(y,sa[i],sa[i-1],k)?p-1:p++;
        }
        if(p>=n)break;
    }
}
void getheight(int n)
{
    int k=0;
    for(int i=0;i<n;i++)rk[sa[i]]=i;
    for(int i=0;i<n;i++)
    {
        if(k)k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k])
        {
            k++;
        }
        height[rk[i]]=k;
    }
}

void st_build(int n)
{
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = height[i];
    }
    for(int j = 1; (1<<j) <= n; j++)
        for(int i = 0; (i+(1<<j)-1) <= n; i++)
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
}

int query(int i, int j)
{
    int l = min(rk[i], rk[j]);
    int r = max(rk[i], rk[j]);
    ++l;
    int cnt = log2(r-l+1), len  = 1<<cnt;
    return min(dp[l][cnt], dp[r-len+1][cnt]);
}
int main()
{
    int t;
    scanf("%d",&t);
    int cont=0;
    while(t--)
    {
        scanf("%d",&num);
        n=0;
        int pos=50;
        for(int i=1;i<=num;i++)
        {
            scanf("%s",str1);
            len=strlen(str1);
            lens[i]=len;
            for(int j=0;j<len;j++)
            {
                s[n++]=str1[j]-'a'+1;
            }
            belong[i]=n-len;
            s[n++]=pos++;
        }
        s[n]=0;
        build_sa(n+1,100500);
        getheight(n+1);
        st_build(n+1);
        int q;
        int u,v;
        scanf("%d",&q);
        printf("Case %d:\n",++cont);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&u,&v);
            if(u==v)printf("%d\n",lens[u]);
            else printf("%d\n",query(belong[u],belong[v]));
        }
    }
}
