/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-03-17 02:19
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size==0) return -1;
        int count = 1;
        int temp = nums[0];
        int i;
        for (i=1; i<size; i++) {
            int tempItem = nums[i];
            if (temp==tempItem) {
                count ++;
            } else {
                count --;
                if (count==0) {
                    temp = nums[i];
                    count = 1;
                }
            }
        }
        return temp;
    }
};

