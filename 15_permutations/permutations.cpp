/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/permutations
@Language: C++
@Datetime: 16-02-07 06:42
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        if (size == 0) return result;
        helper(nums, 0, result);
        return result;
    }
private:
    void helper(vector<int>nums, int pos, vector<vector<int>>&result) {
        if (pos == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i=pos; i<nums.size(); i++) {
            swap(nums[i], nums[pos]);
            helper(nums, pos+1, result);
        }
    }
};
