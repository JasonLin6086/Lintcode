/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/sort-colors
@Language: C++
@Datetime: 15-11-04 15:22
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size<=1) return;
        int pl=0, pr=size-1;
        int current=0;
        while (current<=pr) {
            if (nums[current]==0) {
                swap(nums[current], nums[pl]);
                pl++;
                current++;
            } else if (nums[current]==1) {
                current++;
            } else {
                swap(nums[current], nums[pr]);
                pr--;
            }
        }
    }
};
