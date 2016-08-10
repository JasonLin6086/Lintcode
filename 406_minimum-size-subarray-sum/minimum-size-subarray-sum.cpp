/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/minimum-size-subarray-sum
@Language: C++
@Datetime: 15-11-16 20:16
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        
        int size = nums.size();
        if (size == 0) return -1;
        if (size == 1 && s == nums[0]) return 1;
        unsigned int i, j;
        int length = INT_MAX;
        int localLength = 0;
        int total = 0;
        for (i=0; i<size; i++) {
            total = nums[i];
            localLength = 0;
            if (total == s) return 1;
            for (j=i+1; j<size; j++) {
                total += nums[j];
                if (total >= s) {
                    localLength = j - i + 1;
                    length = min(localLength, length);
                    break;
                }
            }
        }
        return length == INT_MAX ? -1 : length;
        /*
        int minVal = INT_MAX;  
        int curSum =0, start = 0, end = 0;  
        while (end < nums.size()) {  
            curSum += nums[end];  
            while (curSum >= s) {  
                minVal = min(end-start+1, minVal);  
                curSum -= nums[start++];  
            }  
            end++;  
        }  
        return minVal == INT_MAX ? -1 : minVal;  
        */
    }
};
