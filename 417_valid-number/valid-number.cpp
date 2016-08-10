/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/valid-number
@Language: C++
@Datetime: 16-01-29 19:07
*/

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int size = s.size();
        if (size == 0) return false;
        int i=0, j=size-1;
        while (isspace(s[i])) i++;
        while (isspace(s[j])) j--;
        if (s[i]=='+' || s[i]=='-') i++;
        bool hasNumber = false, hasDot = false, hasE = false;
        for (; i<=j; i++) {
            char chr = s[i];
            if (isdigit(chr)) {
                hasNumber = true;
            } else if (chr == '.') {
                if (hasDot || hasE) return false;
                hasDot = true;
            } else if (chr == 'e') {
                if (hasE || !hasNumber) return false;
                hasE = true;
                hasNumber = false;
            } else if (chr == '+' || chr == '-') {
                if (s[i-1] != 'e') return false;
            } else {
                return false;
            }
        }
        return hasNumber;
    }
};