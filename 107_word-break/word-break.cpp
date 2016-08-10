/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/word-break
@Language: C++
@Datetime: 15-11-16 02:17
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        if (s.empty()) return true;
        if (dict.empty()) return false;

        // get the max word length of wordDict
        int max_word_len = 0;
        for (auto itr = dict.begin(); itr != dict.end(); itr++) {
            max_word_len = max(max_word_len, (int)(*itr).size());
        }

        vector<bool> can_break(s.size() + 1);
        can_break[0] = true;
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // optimize for too long interval
                int substrSize = i - j;
                if (substrSize > max_word_len) break;

                if (can_break[j] && 
                    dict.find(s.substr(j, substrSize)) != dict.end()) {
                    can_break[i] = true;
                    break;
                }
            }
        }

        return can_break[s.size()];
    }
};
