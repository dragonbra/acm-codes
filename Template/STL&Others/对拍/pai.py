import os
tc = 0
while True:
    os.system("python gen.py > A.in")
    os.system("time ./F < A.in > std.out")
    os.system("./Fstd < A.in > bf.out")
    if os.system("diff bf.out std.out"):
        print "WA"
        exit(0)
    else:
        tc += 1
        print "AC #%d" %(tc)
    os.system("cat bf.out")
