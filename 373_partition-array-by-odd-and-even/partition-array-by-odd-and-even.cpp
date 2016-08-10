/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 16-07-17 17:33
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size <= 1) return;
        int start = 0, evenIdx = 0;
        while (start < size) {
            if (nums[start] % 2 == 1) {
                swap(nums[start], nums[evenIdx]);
                evenIdx ++;
            }
            start ++;
        }
    }
};