/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/container-with-most-water
@Language: C++
@Datetime: 15-11-07 17:35
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int size = heights.size();
        if (size<=1) return 0;
        int maxVal = 0;
        int left = 0, right = size-1;
        while (left<right) {
            maxVal = max(maxVal,(right-left)*min(heights[left],heights[right]));
            if (heights[left]<heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxVal;
    }
};
