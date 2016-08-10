/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 15-09-03 07:05
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> result;
        int size = strs.size();
        if (size<=1) return result;
        int i;
        unordered_map<string, int> hash;
        for (i=0; i<size; i++) {
            string tmpstr = strs[i];
            sort(tmpstr.begin(), tmpstr.end());
            if (!hash[tmpstr]) {
                hash[tmpstr] = 1;
            } else {
                hash[tmpstr] ++;
            }
        }
        for (i=0; i<size; i++) {
            string tmpstr = strs[i];
            sort(tmpstr.begin(), tmpstr.end());
            if (hash[tmpstr] && hash[tmpstr]>=2) {
                result.push_back(strs[i]);
            }            
        }
        return result;
    }
};

