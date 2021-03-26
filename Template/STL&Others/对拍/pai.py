import os
tc = 0
while True:
    os.system("python gen.py > in.txt")
    os.system("time ./B < in.txt > std.out")
    os.system("./A < in.txt > bf.out")
    if os.system("diff bf.out std.out"):
        print "WA"
        exit(0)
    else:
        tc += 1
        print "AC #%d" %(tc)
    os.system("cat bf.out")
