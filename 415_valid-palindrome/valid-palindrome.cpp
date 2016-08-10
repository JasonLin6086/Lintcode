/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: C++
@Datetime: 16-07-23 20:58
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int size = s.size();
        if (size<=1) return true;
        int left=0, right=size-1;

        while (left<right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            
            if (tolower(s[left++])!=tolower(s[right--])) {
                return false;
            }
            //left++;
            //right--;
        }
        return true;
    }
};
