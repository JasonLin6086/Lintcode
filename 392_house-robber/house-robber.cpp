/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/house-robber
@Language: C++
@Datetime: 16-07-13 17:15
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int size = A.size();
        long long curr=0, prev=0;
        for (int i=0; i<size;i++) {
            long long tmp = max(curr, A[i]+prev);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};