/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 15-11-07 02:46
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int size = s.size();
        if (size == 0) return 0;
        int i;
        while (s[size-1]==' ') {
            size --;
        }
        int count = 0;
        for (i=size-1; i>=0; i--) {
            if (isalpha(s[i])) {
                count++;
            }
            if (isspace(s[i])) {
                return count;
            }
        }
        return count;
    }
};
