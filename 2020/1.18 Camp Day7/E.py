n,p = map(int,input().split())
a = []
a.append(1)
a.append(1)
a.append(2)
a.append(6)
for i in range(4,n+1):
    a.append( ( (-9*i+8)*a[i-1] +2*(13*i-23)*a[i-2] +12*(-2*i+5)*a[i-3] ) // (-i) )
print(a[n]%p)