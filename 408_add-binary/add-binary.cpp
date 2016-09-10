/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 15-12-01 22:04
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int carry = 0;
        unsigned int sizeA = a.size();
        unsigned int sizeB = b.size();
        string rst = "";
        int i = sizeA-1, j = sizeB-1;
        while (i>=0 || j>=0) {
            int x = 0;
            if (i>=0) {
                x += a[i] - '0';
            }
            if (j>=0) {
                x += b[j] - '0';
            }
            x += carry;
            int result = x % 2;
            carry = x / 2;
            rst += to_string(result);
            i--; j--;
        }
        if (carry == 1) {
            rst += to_string(carry);
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};