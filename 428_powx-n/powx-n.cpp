/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 16-02-07 02:00
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n==0) return 1;
        if (n==1) return x;
        double half = myPow(x, n/2);
        if (n%2==0) {
            return half*half;
        } else if (n%2==1) {
            return half*half*x;
        } else {
            return half*half/x;
        }
    }
};