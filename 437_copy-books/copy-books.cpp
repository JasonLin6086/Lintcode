/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/copy-books
@Language: C++
@Datetime: 15-09-26 22:34
*/

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int N = pages.size();
        if(N==0 || k<=0)    return 0;
        k = min(k, N);
        vector<vector<int>> dp(k, vector<int>(N,INT_MAX));
        partial_sum(pages.begin(), pages.end(), dp[0].begin());
        for(int ia=1; ia<k; ++ia){
            dp[ia][ia] = max(pages[ia], dp[ia-1][ia-1]);
            int left = ia, right = ia+1;
            while(right<N){
                int crt = dp[0][right] - dp[0][left];
                dp[ia][right] = min(dp[ia][right], max(dp[ia-1][left], crt));
                if(left<right && crt>dp[ia-1][left]){
                    ++left;
                } else {
                    ++right;
                    if(left>ia) --left;
                }
            }
        }
         
        return dp[k-1][N-1];
    }
};
