/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 16-07-18 16:55
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int x) {
        // Write your code here
        int  res = 0;
        while (x!=0){
            if (res > INT_MAX/10 || res < INT_MIN/10){
                return 0;
            }
            res = res*10 + x%10;
            x= x/10;
        }
        return res;
    }
};
