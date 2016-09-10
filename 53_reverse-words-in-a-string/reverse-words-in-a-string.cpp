/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 16-07-18 22:27
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string result;
        int size = s.size();
        if (size == 0) return result;
        if (size == 1) return s;
        int i;
        string tmpRst;
        for (i=size-1; i>=0; i--) {
            if (!isspace(s[i])) {
                tmpRst += s[i];
            } else {
                if (tmpRst.size()!=0) {
                    reverse(tmpRst.begin(),tmpRst.end());
                    if (result.size()!=0) result += " ";
                    result += tmpRst;
                    tmpRst="";
                }
            }
        }
        if (tmpRst.size()!=0) {
            reverse(tmpRst.begin(),tmpRst.end());
            if (result.size()!=0) result += " ";
            result += tmpRst;
            tmpRst="";
        }
        return result;
    }
};
