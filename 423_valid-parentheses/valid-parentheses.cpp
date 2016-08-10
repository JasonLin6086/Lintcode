/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: C++
@Datetime: 16-08-02 19:25
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> stk;
        int size = s.size();
        for (int i=0; i<size; i++) {
            if (s[i]=='('||s[i]=='{'||s[i]=='[') {
                stk.push(s[i]);
            } else if (s[i]==')'||s[i]=='}'||s[i]==']') {
                if (s[i]==')' && stk.top() != '(') return false;
                if (s[i]=='}' && stk.top() != '{') return false;
                if (s[i]==']' && stk.top() != '[') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};