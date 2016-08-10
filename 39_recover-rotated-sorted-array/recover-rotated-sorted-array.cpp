/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/recover-rotated-sorted-array
@Language: C++
@Datetime: 15-12-01 18:31
*/

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size<=1) {
            return;
        }
        int i;
        for (i=1; i<size; i++) {
            if (nums[i]<nums[i-1]) {
                break;
            }
        }
        rotate(nums.begin(), nums.begin()+i, nums.end());
    }
};
