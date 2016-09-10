/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 15-09-06 21:06
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (n==0) {
            return 1%b;
        } 
        if (n==1) {
            return a%b;
        }
        if (n<0) {
            return -1;
        }
        long long product = fastPower(a, b, n/2);
        product = (product*product)%b;
        if (1==n%2) {
            product = (product*a)%b;
        }
        return (int)product;
    }
};
