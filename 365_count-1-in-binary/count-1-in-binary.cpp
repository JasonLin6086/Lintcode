/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: C++
@Datetime: 16-07-13 17:58
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        while (num != 0) {
            num = num & (num-1);
            count++;
        }
        return count;
    }
};