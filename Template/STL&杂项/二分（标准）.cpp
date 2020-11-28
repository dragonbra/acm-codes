/**
 * struct Interval {
 *	int start;
 *	int end;
 *	Interval(int s, int e) : start(start), end(e) {}
 * };
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 玩偶数
     * @param m int整型 区间数
     * @param intervals Interval类vector 表示区间
     * @return int整型
     */
    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
    
    int doll(int n, int m, vector<Interval>& intervals) {
        // write code here
        long long l = 1, r = n;
        while (l <= r) {
            mid = (l+r) / 2;
            // check code here
            if (flag) {
                ans = mid; l = mid + 1;
            }
            else r = mid - 1;
        }
        
        return ans;
    }
};