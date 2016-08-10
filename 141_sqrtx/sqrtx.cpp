/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: C++
@Datetime: 15-12-04 16:12
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x < 2) return x;
        int start = 1, end = x, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (x/mid > mid) {
                start = mid + 1;
            } else if (x/mid < mid) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return end;
    }
};