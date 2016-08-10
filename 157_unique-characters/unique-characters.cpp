/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 15-11-23 22:52
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        int size = str.size();
        if (size<=1) return true;
        int i;
        unordered_map<char, int> map;
        for (i=0; i<size; i++) {
            if (map[str[i]]) {
                return false;
            } else {
                map[str[i]] = 1;
            }
        }
        return true;
    }
};
