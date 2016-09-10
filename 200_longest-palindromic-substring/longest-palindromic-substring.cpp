/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-palindromic-substring
@Language: C++
@Datetime: 16-02-09 23:17
*/

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        int size = s.size();
        if (size == 0) return "";
        if (size == 1) return s;
        int min_start = 0, length = 1;
        for (int i=0; i<size;) {
            if (size-i <= length/2) break;
            int start=i, end=i;
            while (end < size-1 && s[end+1] == s[end]) end++;
            i = end + 1;
            while (end < size-1 && start > 0 && s[end+1] == s[start-1]) {
                start --; end ++;
            }
            int local_length = end - start + 1;
            if (local_length > length) {
                min_start = start;
                length = local_length;
            }
        }
        return s.substr(min_start, length);
    }
};