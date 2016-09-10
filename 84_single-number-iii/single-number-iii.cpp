/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 15-09-23 05:53
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        // Xor all the elements to get x ^ y.
        int x_xor_y = 0;
        for (const auto& i : A) {
            x_xor_y ^= i;
        }

        // Get the last bit where 1 occurs.
        const auto bit = x_xor_y & ~(x_xor_y - 1);

        // Get the subset of A where the number has the bit.
        // The subset only contains one of the two integers, call it x.
        // Xor all the elements in the subset to get x.
        int x = 0;
        for (const auto& i : A) {
            if (i & bit) {
                x ^= i;
            }
        }

        return {x, x_xor_y ^ x};
    }
};
