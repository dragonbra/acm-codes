import operator
def c(n,k):
    return reduce(operator.mul, range(n - k + 1, n + 1)) /reduce(operator.mul, range(1, k +1))
 
 
def fac(n):
    return reduce(operator.mul, range(1,n+1))
 

print(c(42,25))