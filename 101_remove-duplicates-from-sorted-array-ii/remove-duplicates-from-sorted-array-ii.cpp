/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 15-11-08 01:47
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size<=2) {
            return size;
        }
        int i;
        int index = 1;
        for (i=2; i<size; i++) {
            if (nums[i]!=nums[index] || nums[i]!=nums[index-1]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};
