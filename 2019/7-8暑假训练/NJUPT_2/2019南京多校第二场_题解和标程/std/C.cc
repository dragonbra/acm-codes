#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int main(){
    int n;
    scanf("%d", &n);
    int mx = -1;
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        if(!s.empty()){
            if(s.top() < x)return printf("No"),0;
            if(s.top() == x)s.pop();
            else if(s.top() > x)s.push(x);
        }
        else s.push(x);
    }
    if(s.size() > 1) return printf("No"),0;
    else if(s.size() == 1){
        if(s.top() < mx) return printf("No"),0;
    }
    printf("Yes");
    return 0;
}