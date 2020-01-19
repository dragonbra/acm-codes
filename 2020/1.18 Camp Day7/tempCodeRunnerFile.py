def _list(n) :

    D = [0]*(n+1); D[1] = 1

    b = True; h = 1; R = []

    for i in range(2*n) :

        if b :

            for k in range(h, 0, -1) : 
                D[k] += D[k-1]
                D[k] %= p

            h += 1;

        else :

            for k in range(1, h, 1) : 
                D[k] += D[k-1]
                D[k] %= p
            R.append(D[h-1]);

        b = not b

    return R

n,p = map(int,input().split())
RR = _list(100)
print(RR[n-1])