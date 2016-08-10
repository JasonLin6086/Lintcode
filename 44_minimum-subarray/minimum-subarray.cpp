/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 16-07-17 16:37
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        int lmin = nums[0], minVal = nums[0];
        for (int i=1; i<nums.size(); i++) {
            lmin = min(lmin+nums[i], nums[i]);
            minVal = min(lmin, minVal);
        }
        return minVal;
    }
};
