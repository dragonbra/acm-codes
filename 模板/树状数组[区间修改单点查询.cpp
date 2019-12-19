int n,m;
int a[50005] = {0},c[50005]; //对应原数组和树状数组

int lowbit(int x){
    return x&(-x);
}

void updata(int i,int k){    //在i位置加上k
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

int getSum(int i){        //求D[1 - i]的和，即A[i]值
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main(){
    cin>>n;27     for(int i = 1; i <= n; i++){
        cin>>a[i];
        updata(i,a[i] - a[i-1]);   //输入初值的时候，也相当于更新了值
    }

    //[x,y]区间内加上k
    updata(x,k);    //A[x] - A[x-1]增加k
    updata(y+1,-k);        //A[y+1] - A[y]减少k

    //查询i位置的值
    int sum = getsum(i);

    return 0;
}
