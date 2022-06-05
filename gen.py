import random

n = random.randint(1, 10)
k = random.randint(n, 10)

vis = [False for i in range(k + 1)]
arr = []

print(n, k)
for i in range(n):
    a = 0
    while vis[a] != 0:
        a = random.randint(0, k - 1)
    vis[a] = True
    arr.append(a)

arr = sorted(arr)
for i in range(n):
    print(arr[i], end = ' ')
print()