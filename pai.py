import os

kase = 0
while True:
    print("----------")
    os.system("python3 gen.py >_.in")
    os.system("time ./A_brute <_.in >_std.out")
    os.system("./A <_.in >_.out")
    print()
    
    if os.system("diff _.out _std.out"):
        print("WA")
        os.system("cat _.out")
        os.system("cat _std.out")
        exit(0)
    else:
        kase += 1
        print("AC #%d" %(kase))
    print()
