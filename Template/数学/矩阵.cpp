const int N = 1010;
const int M = 1010;
struct Matrix{
    int n,m;
    int a[N][M];
    void clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator + (const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
        return tmp;
    }
    Matrix operator - (const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
        return tmp;
    }
    Matrix operator * (const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        tmp.n=n; tmp.m=m;
        for(int i=0; i<n; ++i)
            for(int j=0;j<b.m; ++j)
                for(int k=0; k<m; ++k)
                    tmp.a[i][j] += a[i][k] * b.a[k][j];
        return tmp;
    }
}