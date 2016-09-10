/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: C++
@Datetime: 16-07-17 16:41
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int size = nums.size();
        if (size == 0) return;
        int i = 0, zeroIdx = 0;
        while (i < size) {
            if (nums[i] != 0) {
                swap(nums[i], nums[zeroIdx]);
                zeroIdx ++;
            }
            i ++;
        }
    }
};