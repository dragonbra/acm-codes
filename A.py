# 读入数据
target = int(input())
a = list(map(int, input().split()))

n = len(a) # n是数组的长度
suf0 = [0 for _ in range(n + 1)] # suf0[i]表示从i开始有多少个连续的0（包括a[i]自己）

# 预处理suf0[i]，从后往前遍历
for i in range(n - 1, -1, -1):
    if a[i] == 0:
        # 如果a[i]是0，那从这里开始的0数量+1
        suf0[i] = suf0[i + 1] + 1
    else:
        # 否则从这里开始的0数量=0
        suf0[i] = 0

acc = 0 # 记录[l, r]这段区间的和
pt = 0 # pt代表上述的l
ans = 0 # 方案数量
for i in range(n):
    # i 代表上述的r
    acc += a[i]
    if acc > target:
        # 如果此时和已经>target了，向右移动左端点
        while acc > target:
            acc -= a[pt]
            pt += 1
    
    # 如果区间和==target，累加合法方案数
    if acc == target:
        ans += 1 + suf0[pt]

print(ans)  