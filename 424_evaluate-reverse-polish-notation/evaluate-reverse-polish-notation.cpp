/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 16-01-29 19:02
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        int size = tokens.size();
        if (size == 0) return 0;
        stack<int> stk;
        int i;
        for (i=0; i<size; i++) {
            string str = tokens[i];
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int b = stk.top(); 
                stk.pop();
                int a = stk.top();
                stk.pop();
                int result;
                if (str == "+") result = a + b;
                if (str == "-") result = a - b;
                if (str == "*") result = a * b;
                if (str == "/") {if (b == 0) return 0; result = a / b;}
                stk.push(result);
            } else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};