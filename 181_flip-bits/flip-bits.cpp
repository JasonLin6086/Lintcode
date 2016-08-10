/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-07-13 18:42
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int count=0;
        int a_xor_b = a^b;
        while (a_xor_b!=0) {
            count++;
            a_xor_b = a_xor_b & (a_xor_b-1);
        }
        return count;
    }
};
