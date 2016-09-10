/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-increasing-subsequence
@Language: C++
@Datetime: 15-12-07 22:34
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size==0) return 0;
        vector<int> result(size,1);
        int i, j;
        for (i=1; i<size; i++) {
            for (j=0; j<i; j++) {
                if (nums[j]<=nums[i] && (result[i]<result[j]+1)) {
                    result[i] = result[j] + 1;
                }
            }
        }
        return *max_element(result.begin(), result.end());
    }
};

