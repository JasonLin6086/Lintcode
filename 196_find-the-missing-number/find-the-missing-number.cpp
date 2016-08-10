/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-the-missing-number
@Language: C++
@Datetime: 15-07-25 05:57
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int i;
        int size = nums.size()-1;
        
        int total = (size+1)*(size+2)/2;
        for (i=0; i<=size; i++) {
            total -= nums[i];
        }
        return total;
    }
};
