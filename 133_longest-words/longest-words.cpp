/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 16-03-17 02:17
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int size = dictionary.size();
        int i;
        int length = INT_MIN;
        vector<string> result;
        for (i=0; i<size; i++) {
            int itemSize = dictionary[i].size();
            if (itemSize > length) {
                result.clear();
                length = itemSize;
                result.push_back(dictionary[i]);
            } else if (itemSize == length) {
                result.push_back(dictionary[i]);
            }
        }
        return result;
    }
};
