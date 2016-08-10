/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/paint-house-ii
@Language: C++
@Datetime: 16-03-22 18:15
*/

class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size(), m1 = 0, m2 = 0;
        vector<int> dp(k, 0);
        for (int i = 0; i < n; i++) {
            int t1 = m1, t2 = m2;
            m1 = m2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                dp[j] = (dp[j] != t1 ? t1 : t2) + costs[i][j];
                if (m1 <= dp[j]) m2 = min(m2, dp[j]);
                else m2 = m1, m1 = dp[j];
            }
        }
        return m1;
    }
};