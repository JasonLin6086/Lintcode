/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/word-ladder
@Language: C++
@Datetime: 16-02-07 01:48
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        dict.insert(end);
        queue<string> visited;
        helper(start, dict, visited);
        int count=2;
        while (!visited.empty()) {
            int size = visited.size();
            for (int i=0; i<size; i++) {
                string str = visited.front();
                visited.pop();
                if (str == end) { return count; }
                helper(str, dict, visited);
            }
            count++;
        }
        return 0;
    }
private:
    void helper(string word, unordered_set<string>&dict, queue<string>&visited) {
        dict.erase(word);
        int i, j;
        for (i=0; i<word.length(); i++) {
            char ch = word[i];
            for (j=0; j<26; j++) {
                word[i] = 'a' + j;
                if (dict.find(word) != dict.end()) {
                    visited.push(word);
                    dict.erase(word);
                }
            }
            word[i] = ch;
        }
    }
};