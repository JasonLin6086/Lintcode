/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/coins-in-a-line
@Language: C++
@Datetime: 15-11-06 18:10
*/

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        return n % 3 != 0;
    }
};
