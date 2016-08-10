/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 15-10-19 21:41
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m<1 || n<1) return 0;
        vector<vector<int>> result(m,vector<int>(n,1));
        int i, j;
        for (i=1; i<m; i++) {
            for (j=1; j<n; j++) {
                result[i][j] = result[i-1][j] + result[i][j-1]; 
            }
        }
        return result[m-1][n-1];
    }
};

