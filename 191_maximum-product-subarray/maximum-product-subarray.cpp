/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 16-01-29 19:56
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int size = nums.size();
        if (size == 0) return 0;
        int i;
        int localMin=nums[0], localMax=nums[0], maxV=nums[0];
        for (i=1; i<size; i++) {
            int tmpMax = localMax;
            localMax = max(tmpMax*nums[i], max(localMin*nums[i], nums[i]));
            localMin = min(tmpMax*nums[i], min(localMin*nums[i], nums[i]));
            maxV = max(maxV, localMax);
        }
        return maxV;
    }
};