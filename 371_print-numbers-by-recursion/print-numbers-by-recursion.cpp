/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 15-09-20 17:29
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;
        if (n<=0) return result;
        helper(n, result);
        return result;
    }
private:
    void helper(int n, vector<int> &rst) {
        if (n==0) return;
        helper(n-1, rst);
        int base = pow(10, n-1);
        int size = rst.size();
        for (int i=1; i<10; i++) {
            //push 10, 100,...
            rst.push_back(i*base);
            for (int j=0; j<size; j++) {
                //push 11, 12, ...
                rst.push_back(rst[j]+i*base);
            }
        }
    }
};
