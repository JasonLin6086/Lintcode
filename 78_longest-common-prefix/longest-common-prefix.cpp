/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 15-09-03 07:23
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        int size=strs.size();
        if (size==0) return "";
        if (size==1) return strs[0];
        int i, j, k, l;
        int max_length=INT_MAX;
        bool flag=false;
        for (i=0; i<size; i++) {
            max_length = min(max_length, (int)strs[i].length());
        }
        for (k=0; k<max_length; k++) {
            for (l=0; l<size-1; l++) {
                if (strs[l][k]==strs[l+1][k]) {
                    flag = true;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if (!flag) break;
        }
        string ans = "";
        for(int n = 0; n < k; n++) {
            ans += strs[0][n];
        }
        return ans;
        
    }
};
