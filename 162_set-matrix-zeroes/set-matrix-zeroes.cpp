/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/set-matrix-zeroes
@Language: C++
@Datetime: 16-04-14 19:34
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        if (m==0) return;
        int n = matrix[0].size();
        if (n==0) return;
        int i, j;
        bool col = false;
        for (i=0; i<m; i++) {
            if (matrix[i][0]==0) col = true;
            for (j=1; j<n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (i=m-1; i>=0; i--) {
            for (j=n-1; j>=1; j--) {
                if (matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
            if (col) matrix[i][0] = 0;
        }
    }
};