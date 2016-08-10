/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/matrix-zigzag-traversal
@Language: C++
@Datetime: 16-07-14 17:31
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> zigzag;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2) {
                for (int y = min(i, n - 1);  y >= max(0, i - m + 1); --y) {
                    zigzag.push_back(matrix[i - y][y]);
                }
            } else {
                for (int x = min(i, m - 1);  x >= max(0, i - n + 1); --x) {
                    zigzag.push_back(matrix[x][i - x]);
                }
            }
        }

        return zigzag;
    }
};
