#random replacement algorithm
import random,sys
class RRCache:
    def __init__(self,_max_size):
        self.max_size = _max_size
        self.total_size = 0;
        self.vec=[]
        self.st=set()

    def put(self,fID:int,fsize:int):
        invalfIDs=[]
        while self.total_size+fsize>self.max_size:
            idx=random.randint(0,len(self.vec)-1)
            self.vec[idx],self.vec[-1]=self.vec[-1],self.vec[idx]
            t=self.vec[-1]
            del(self.vec[-1])
            invalfIDs.append(t[0])
            self.st.remove(t[0])
            self.total_size-=t[1]

        self.total_size+=fsize
        self.vec.append((fID,fsize))
        self.st.add(fID)
        return invalfIDs

if __name__ == "__main__":

    n,m,k,C=map(int,input().split())
    buffer=RRCache(k)
    total_cost=0
    for _ in range(m):
        fID,fsize,hit=map(int,input().split())
        if hit==1:
            print("0")
        else:
            total_cost+=fsize+C;

            v=buffer.put(fID,fsize)
            print("%lu"%(len(v)))
            if len(v)!=0:
                for item in v:
                    print("%09d "%item,end='')
                print("")
        sys.stdout.flush()

