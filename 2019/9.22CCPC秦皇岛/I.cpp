#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fff7fff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

char s[N]; int a[N]; int dp[N][28];
int tb[11][11] = {{0},{1,0},{2,4,10,0},{3,7,19,0},{14,0},{5,11,13,0},{15,17,23,0},{27,0},{9,21,25,0},{18,24,26,0},{6,8,12,16,20,22,0}};

int cnt(int u,int v){
    if(u==v) return 0;
    
    u-=1,v-=1;
	int s1[5],s2[5];
    for(int i=1;i<=3;i++) s1[3-i+1]=u%3, u/=3, s2[3-i+1]=v%3, v/=3;

    if(s1[2]==s2[1]&&s1[3]==s2[2]) return 1;
    else if(s1[3]==s2[1]) return 2;
    else return 3;
}

int main() {
	redirect();
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++){
        switch(s[i]){
            case 'Y':{ a[i]=1; break; }
            case 'V':{ a[i]=2; break; }
            case 'G':{ a[i]=3; break; }
            case 'C':{ a[i]=4; break; }
            case 'X':{ a[i]=5; break; }
            case 'Z':{ a[i]=6; break; }
            case 'T':{ a[i]=7; break; }
            case 'F':{ a[i]=8; break; }
            case 'D':{ a[i]=9; break; }
            case 'B':{ a[i]=10; break; }
        }
	}

	for(int i=0;i<len;i++)
		for(int j=1;j<=27;j++)
			dp[i][j] = INF;

	for(int i=0;i<len;i++){
		int x = a[i]; cout<<x<<": ";
        if(i==0) for(int k=0;tb[x][k]!=0;k++) dp[i][tb[x][k]]=3;
        else{
            for(int k=0;tb[x][k]!=0;k++){
            	int idx = tb[x][k]; cout<<idx<<' ';
          	  	for(int j=1;j<=27;j++){
                    dp[i][idx] = min( dp[i][idx], dp[i-1][j] + cnt(j,idx) );
                }
            }
        }
        cout<<endl;
	}

	///*
	for(int i=1;i<=27;i++) cout<<setw(2)<<i<<' '; cout<<endl;
	for(int i=0;i<len;i++) {
		for(int j=1;j<=27;j++) if(dp[i][j]==INF) cout<<setw(2)<<0<<' '; else  cout<<setw(2)<<dp[i][j]<<' ';
		cout<<endl;
	}
	cout<<len<<endl; 
	//*/ 

    int ans = INF;
    for(int i=1;i<=27;i++){
        ans = min(ans, dp[len-1][i]);
    }
    ans+=len;
    printf("%d\n",ans);
}

/*
-------------------
 author:dragon_bra
-------------------
*/
