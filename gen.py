import random

<<<<<<< Updated upstream
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
=======
NODE_N = 4
MIN_DIS = 1
MAX_DIS = 10

n = NODE_N
mp = [[0 for _ in range(n)] for __ in range(n)]

for i in range(n):
    for j in range(n):
        if j < i:
            mp[i][j] = mp[j][i]
        elif i == j:
            mp[i][j] = 0
        else:
            mp[i][j] = random.randint(MIN_DIS, MAX_DIS)

print(n)
for i in range(n):
    for j in range(n):
        print(mp[i][j], end=" ")
    print()
>>>>>>> Stashed changes
