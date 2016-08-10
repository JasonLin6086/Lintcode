/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/next-permutation-ii
@Language: C++
@Datetime: 16-03-28 15:29
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int k = -1, l = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        } 

        if (k >= 0) {
            for (int i = nums.size() - 1; i > k; i--) {
                if (nums[i] > nums[k]) {
                    l = i;
                    break;
                } 
            } 
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());         
    }
};