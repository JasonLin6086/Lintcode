/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/maximal-rectangle
@Language: C++
@Datetime: 16-03-13 02:19
*/

class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        int result = 0;
        int row = matrix.size();
        if (row == 0) return result;
        int col = matrix[0].size();
        if (col == 0) return result;
        int i, j;
        vector<vector<int>> heights(row, vector<int>(col+1, 0));
        for (j=0; j<col; j++) {
            for (i=0; i<row; i++) {
                if (!matrix[i][j]) {
                    heights[i][j]=0;
                }
                else if (i==0 && matrix[i][j]) heights[0][j] = 1;
                else heights[i][j] = heights[i-1][j]+1;
             }
        }
        int maxValue = 0;
        for (i=0; i<row; i++) {
            int stk[col+1];
            int idx = -1;
            for (j=0; j<col+1; j++) {
                if (idx == -1 || heights[i][j] > heights[i][stk[idx]]) stk[++idx] = j;
                else {
                    int tmp = stk[idx--];
                    maxValue = max(maxValue, heights[i][tmp] * (idx==-1 ? j : j-stk[idx]-1));
                    j--;
                }
            }
        }
        return maxValue;
    }
};