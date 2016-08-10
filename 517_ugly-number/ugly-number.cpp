/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 16-03-24 17:13
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        for (int i=2; i<6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};