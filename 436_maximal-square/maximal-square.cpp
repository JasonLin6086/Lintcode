/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/maximal-square
@Language: C++
@Datetime: 15-12-08 18:16
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int row = matrix.size();
        if (row==0) return 0;
        int col = matrix[0].size();
        if (col==0) return 0;
        int i, j;
        vector<vector<int>> square(row,vector<int>(col));
        for (i=row-1; i>=0; i--) {
            for (j=col-1; j>=0; j--) {
                if (matrix[i][j]==1) {
                    if (i==row-1 || j==col-1) {
                        square[i][j] = 1;
                    } else {
                        int maxsquare = min(square[i+1][j+1], min(square[i+1][j],square[i][j+1]));
                        square[i][j] = maxsquare + 1;
                    }
                } else {
                    square[i][j] = 0;
                }
            }
        }
        int maxval = square[0][0];
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++)
                maxval = max(maxval, square[i][j]);
        }
        return maxval*maxval;
    }
};
