import sys
def power(base,exponent):
    res = 1
    while exponent:
        if exponent & 1:  # 判断当前的最后一位是否为1，如果为1的话，就需要把之前的幂乘到结果中。
            res *= base
        base *= base  # 一直累乘，如果最后一位不是1的话，就不用了把这个值乘到结果中，但是还是要乘。
        exponent = exponent >> 1
    return res

T = input()
T = int(T)
for i in range(T):
    a, b, c, d, e, f, g = map(int,sys.stdin.readline().split())
    if( power(a,d) + power(b,e) + power(c,f) == g ): 
        print("Yes")
    else:
        print("No")