/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/jump-game-ii
@Language: C++
@Datetime: 15-09-08 16:53
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int current_jump = 0;
        int current_reachable = 0;
        int max_reachable = 0;
        int i;
        for (i=0; i<A.size(); i++) {
            if (i > max_reachable) {
                return -1;
            }
            if (i > current_reachable) {
                current_reachable = max_reachable;
                current_jump++;
            }
            max_reachable = max(max_reachable, i+A[i]);
        }
        return current_jump;
    }
};
