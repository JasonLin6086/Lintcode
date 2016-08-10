/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 16-01-29 20:17
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size == 0) return 0;
        int local = nums[0], maxV = nums[0];
        for (int i=1; i<size; i++) {
            local = max(local + nums[i], nums[i]);
            maxV = max(local, maxV);
        }
        return maxV;
    }
};
