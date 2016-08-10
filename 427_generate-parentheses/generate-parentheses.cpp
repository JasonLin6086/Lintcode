/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/generate-parentheses
@Language: C++
@Datetime: 16-06-29 20:32
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> result;
        string curStr = "";
        helper(n, 0, 0, curStr, result);
        return result;
    }
private:
    void helper(int n, int nleft, int nright, string &curStr, vector<string> &result) {
        if (n==nleft && n==nright) {
            result.push_back(curStr);
            return;
        }
        
        if (nleft < n) {
            curStr.push_back('(');
            helper(n, nleft+1, nright, curStr, result);
            curStr.pop_back();
        }
        
        if (nright < nleft) {
            curStr.push_back(')');
            helper(n, nleft, nright+1, curStr, result);
            curStr.pop_back();
        }        
    }
};