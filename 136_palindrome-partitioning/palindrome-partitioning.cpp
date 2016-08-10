/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning
@Language: C++
@Datetime: 16-08-10 18:53
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> tmp;
        getPartition(s, 0, tmp, res);
        return res;
    }
private: 
    void getPartition(string& s, int idx, vector<string>& tmp, vector<vector<string>>& res) {
        if (idx == s.length()) {
            res.push_back(tmp);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            int l = idx, r = i;
            while (l < r && s[l] == s[r]) l++, r--;
            if (l >= r) {
                tmp.push_back(s.substr(idx, i - idx + 1));
                getPartition(s, i + 1, tmp, res);
                tmp.pop_back();
            }
        }
    }
};