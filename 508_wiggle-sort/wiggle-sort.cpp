/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/wiggle-sort
@Language: C++
@Datetime: 16-06-30 15:13
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        for (int i=1; i<nums.size(); i++)
            if (i%2 == (nums[i-1] > nums[i]))
                swap(nums[i-1], nums[i]);
    }
};