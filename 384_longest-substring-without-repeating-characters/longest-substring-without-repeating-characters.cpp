/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-substring-without-repeating-characters
@Language: C++
@Datetime: 16-08-10 06:33
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int size=s.size();
        if (size==0) return 0;
        int start=0, maxLength=0;
        int hash[255] = {0};
        int i;
        for (i=0; i<size; i++) {
            int length;
            if (hash[(int)s[i]] > 0) {
                start = max(start, hash[(int)s[i]]);
            }
            length = i - start + 1;
            maxLength = max(length,  maxLength);
            hash[(int)s[i]] = i + 1;
        }
        return maxLength;
    }
};