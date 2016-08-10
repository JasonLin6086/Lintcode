/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-07-23 20:50
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        int i, strVal;
        char maps[255] = {};
        if (s.size() != t.size()) return false;
        for (i=0; i<s.size(); i++) {
            strVal = (int)s[i];
            maps[strVal]++;
            strVal = (int)t[i];
            maps[strVal]--;
        }
        for (i=0; i<255; i++) {
            if (maps[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
