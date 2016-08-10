/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/house-robber-ii
@Language: C++
@Datetime: 16-07-13 17:19
*/

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        return max(helper(nums, 0, size-2), helper(nums, 1, size-1));
    }
private:
    int helper(vector<int>&nums, int start, int end) {
        int prev=0, curr=0;
        for (int i=start; i<=end; i++) {
            int tmp = max(prev+nums[i], curr);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};