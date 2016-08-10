/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 15-10-19 21:35
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m = grid.size();
        if (m==0) return -1;
        int n = grid[0].size();
        if (n==0) return -1;
        vector<vector<int>> result(m,vector<int>(n,0));
        int i, j;
        result[0][0] = grid[0][0];
        for (i=1; i<m; i++) {
            result[i][0] = result[i-1][0] + grid[i][0];
        }
        for (i=1; i<n; i++) {
            result[0][i] = result[0][i-1] + grid[0][i];
        }
        for (i=1; i<m; i++) {
            for (j=1; j<n; j++) {
                result[i][j] = grid[i][j] + min(result[i-1][j],result[i][j-1]);
            }
        }
        return result[m-1][n-1];
    }
};

