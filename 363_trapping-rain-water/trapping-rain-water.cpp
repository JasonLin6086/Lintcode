/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/trapping-rain-water
@Language: C++
@Datetime: 15-09-26 18:39
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int size = heights.size();
        if (size < 3) return 0;
        vector<int> left(size);
        int sum = 0, right = 0;
        int i;
        for (i=1; i<size; i++) {
            left[i] = max(left[i-1], heights[i-1]);
        }
        for (i=size-2; i>=0; i--) {
            right = max(right, heights[i+1]);
            int height = min(right, left[i]);
            int tmpSum = heights[i]>=height?0:height-heights[i];
            sum+=tmpSum;
        }
        return sum;
    }
};
