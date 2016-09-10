/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/paint-house
@Language: C++
@Datetime: 16-03-22 18:14
*/

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int n = costs.size();
        for (int i = 1; i < n; i++) {
            costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
        }
        return (n == 0) ? 0 : (std::min(costs[n - 1][0], std::min(costs[n - 1][1], costs[n - 1][2])));
    }
};