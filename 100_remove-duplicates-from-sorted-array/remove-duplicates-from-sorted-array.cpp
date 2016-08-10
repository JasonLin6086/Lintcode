/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-07-17 18:14
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
/*        int size=nums.size();
        if (size==0) {return nums.size();}
        int idx=0, tmpVal=nums[0], i;
        for (i=1; i<=size; i++) {
            while (nums[i]==tmpVal) {
                i++;
            }
            if (i<=size) {
                nums[idx] = tmpVal;
                tmpVal = nums[i];
                idx++;
            }
        }
        nums.resize(idx);
        return nums.size();
*/
        int size = nums.size();
        if (size<=1) {
            return size;
        }
        int i;
        int index = 0;
        for (i=1; i<size; i++) {
            if (nums[i]!=nums[index]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};
