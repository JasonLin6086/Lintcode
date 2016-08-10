/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/decode-ways
@Language: C++
@Datetime: 16-03-14 20:31
*/

int dp[1000] = {0}; 
class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        int size = s.size();
        if (size==0) return 0;

        dp[size] = 1;
        for (int i=size-1; i>=0; i--) {
            if (s[i]=='0') {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i+1];
            if (i<size-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) {
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};