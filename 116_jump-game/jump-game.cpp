/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: C++
@Datetime: 15-09-08 16:46
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int reachable = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > reachable) {
                return false;
            }
            reachable = max(reachable, i + A[i]);
        }

        return true;
    }
};

