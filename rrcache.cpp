//random 瞎搞 algorithm
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>

class RRCache{
    int max_size;
    int total_size;
    std::vector<std::pair<int,int> > vec;
    std::set<int> st;
    std::unordered_map<int, int> pos;
    public:
    RRCache(int max_size):max_size(max_size),total_size(0){}

    void LRU_fake(int fID) {
        swap(vec[pos[fID]], vec[0]);
    }
    
    std::vector<int> put(int fID,int fsize){
        assert(st.count(fID)==0);
        std::vector<int > invalfIDs;
        while(total_size + fsize > max_size){
            // int idx = rand() % vec.size();
            // swap(vec[idx],vec.back());

            auto t = vec.back();
            vec.pop_back();
            invalfIDs.push_back(t.first);
            st.erase(t.first);
            total_size -= t.second;
        }

        total_size += fsize;
        vec.emplace_back(fID,fsize);
        st.insert(fID);
        return invalfIDs;
    }
};

int n,m,k,C;
std::vector<int> invalfIDs;

int main(int argc, char **argv) {
    srand(unsigned(time(NULL)));
    scanf("%d%d%d%d",&n,&m,&k,&C);

    int fID,fsize;

    RRCache* buffer=new RRCache(k);
    int hit;
    int total_cost=0;
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&fID,&fsize,&hit);
        if(hit){
            buffer->LRU_fake(fID);
            printf("0\n");
        }else{
            total_cost+=fsize+C;

            auto v=buffer->put(fID,fsize);
            printf("%lu\n",v.size());
            if(v.size()!=0){
                for(int j=0;j<v.size();j++){
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
