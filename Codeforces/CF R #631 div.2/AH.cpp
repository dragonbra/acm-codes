#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}



int main() {
    redirect();

    int t = 1; cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        map<int, int> ma;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ma[arr[i]]++;
        }
        int j =1;
        for(int i=0;i<m;i++){
            while(ma[j]!=0){
                j++;
            }
            j++;
            while(ma[j]!=0){
                j++;
            }
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/