/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 16-07-17 17:48
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int size = digits.size();
        int carryon=1, i, tmpVal;
        for (i=size-1; i>=0; i--) {
            tmpVal = digits[i];
            int newVal = tmpVal + carryon;
            carryon = newVal / 10;
            digits[i] = newVal % 10;
            if (carryon == 0) break;
        }
        if (carryon == 1) {
            digits.insert(digits.begin(), carryon);
        }
        return digits;
    }
};