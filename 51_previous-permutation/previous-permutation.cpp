/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/previous-permutation
@Language: C++
@Datetime: 16-03-28 15:25
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        //prev_permutation(nums.begin(), nums.end());
        int k = -1, l = 0;

        // Find the last index k before the increasing sequence.
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                k = i;
            }
        }

        if (k >= 0) {
            // Find the largest number which is smaller than the value of the index k,
            // and swap the values.
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }

        // Reverse the sequence after the index k.
        reverse(nums.begin() + k + 1, nums.end());

        return nums;
    }
};