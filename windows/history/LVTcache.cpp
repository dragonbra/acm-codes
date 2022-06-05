/*
*  @ author: dragon_bra
*  @ created at: 2021-12-15 11:08:29
*  lowest visit times algorithm
*/
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>

struct node {
    int fID, fsize, t;
    friend bool operator < (node a, node b) {
        return a.t >= b.t;
    }
};

class RRCache{
    int max_size;
    int total_size;
    std::set<int> st;
    std::unordered_map<int, int> lastVis;
    std::priority_queue<node> PQ;

    public:
    RRCache(int max_size):max_size(max_size),total_size(0){}

    void LRU(int fID, int fsize, int t) {
        lastVis[fID] ++;
        PQ.push({fID, fsize, lastVis[fID]});
    }
    
    std::vector<int> put(int fID,int fsize, int t) {
        assert(st.count(fID)==0);
        std::vector<int > invalfIDs;
        while(total_size + fsize > max_size){

            while (PQ.size() && lastVis[PQ.top().fID] != PQ.top().t) {
                PQ.pop();
            }

            node now = PQ.top(); PQ.pop();
            invalfIDs.push_back(now.fID);
            st.erase(now.fID);
            total_size -= now.fsize;
        }

        total_size += fsize;
        lastVis[fID] ++;
        PQ.push({fID, fsize, lastVis[fID]});
        st.insert(fID);
        return invalfIDs;
    }
};

int n, m, k, C;

int main(int argc, char **argv) {

    scanf("%d %d %d %d",&n, &m, &k, &C);

    int fID, fsize;

    RRCache* buffer=new RRCache(k);
    int hit;
    int total_cost=0;
    for (int i = 0; i < m; i ++ ) {
        scanf("%d %d %d",&fID, &fsize, &hit);
        if (hit) {
            buffer->LRU(fID, fsize, i);
            printf("0\n");
        } else {
            total_cost += fsize + C;

            auto v = buffer->put(fID, fsize, i);

            printf("%lu\n",v.size());
            if (v.size() != 0) {
                for(int j = 0; j < v.size(); j++){
                    printf("%09d ",v[j]);                    
                }
                printf("\n");
            }
        }
        fflush(stdout);
    }
    delete buffer;
    return 0;
}
