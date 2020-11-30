#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 +10;
const ll mod = 1e9 +7;
const double eps = 1e-8;
int n,m;
int a[N][20],f[N][20],cf[30],t[N],p[N];
map<int,int>mp;
map<int,int>::iterator it1,it2;
bitset<32770>s[20];
int ch[20],chcnt;
int check(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)f[i][j]=0;
        t[i]=0;p[i]=0;
    }
    for(int i=0;i<20;i++)s[i].reset(),ch[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]>=x)f[i][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(f[i][j])t[i]+=cf[j-1];
    }
    mp.clear();
    int y=cf[m]-1,pcnt=0;
    for(int i=1;i<=n;i++)mp[t[i]]++;
    for(it1=mp.begin();it1!=mp.end();it1++)p[++pcnt]=it1->first;
    for(int i=1;i<=pcnt;i++){
        //if(x==1961)printf("%d\n",p[i]);
        int xx=p[i],scnt=0;
        while(xx){
            scnt++;
            if(xx%2)s[scnt][i]=1;
            xx/=2;
        }
    }
    for(int i=1;i<=pcnt;i++){
        chcnt=0;
        int xx=p[i]^y,scnt=0;
        while(xx){
            scnt++;
            if(xx%2)ch[++chcnt]=scnt;
            xx/=2;
        }
        //if(x==1961)printf("%d\n",chcnt);
        s[18]=s[ch[1]];
        for(int j=2;j<=chcnt;j++)
            s[18]&=s[j];
        if(s[18].count())return true;
    }
    return false;

}
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T;
    //scanf("%d",&T);
    T=1;
    cf[0]=1;    
    for(int i=1;i<=20;i++)cf[i]=cf[i-1]*2; 
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
        int l=1,r=1e9,ans=0;
        //printf("%d\n",check(1961));
        while(l<=r){
            int mid=(l+r)>>1;
           // cout<<l<<" "<<mid<<endl;
          //  cout<<check(3)<<endl;
            if(check(mid))ans=max(ans,mid),l=mid+1;
            else r=mid-1;
           // if(mid==3)cout<<l<<endl;
        }
        for(int i=1;i<=n;i++){
            sort(a[i]+1,a[i]+1+m);
            ans=max(ans,a[i][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}