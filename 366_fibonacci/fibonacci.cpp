/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 16-07-12 21:08
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int n_i=0, n_i_1=1, n_i_2=0;
        for (int i=2; i<n; i++) {
            n_i = n_i_1 + n_i_2;
            n_i_2 = n_i_1;
            n_i_1 = n_i;
        }
        return n_i;
    }
};
