/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 16-06-30 02:01
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size()==0 || matrix[0].size()==0) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int curRow = 0, curCol = col-1, times;
        while (curRow < row && curCol >=0) {
            if (matrix[curRow][curCol] == target) {
                times ++;
                curCol --;
            } else if (matrix[curRow][curCol] > target) {
                curCol --;
            } else {
                curRow ++;
            }
        }
        return times;
    }
};
