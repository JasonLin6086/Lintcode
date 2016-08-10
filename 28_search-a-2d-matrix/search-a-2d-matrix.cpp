/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 15-12-01 17:17
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
/*        if (matrix.size()==0) return false;
        if (matrix[0].size()==0) return false;
        if(target< matrix[0][0]) return false;
        int start=0, end=matrix.size()-1, mid;
        while (start<=end) {
            mid = (start + end) / 2;
            if (matrix[mid][0]==target) return true;
            if (matrix[mid][0]>target) end = mid-1;
            else start = mid+1;
        }
        int row = end;
        start=0, end=matrix[0].size()-1;
        while (start<=end) {
            mid = (start + end) / 2;
            if (matrix[row][mid]==target) return true;
            if (matrix[row][mid]>target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
        */
        if (matrix.size()==0) return false;
        if (matrix[0].size()==0) return false;
        if(target < matrix[0][0]) return false;
        int row = 0, col = matrix[0].size()-1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) {
                col --;
            } else if (matrix[row][col] < target) {
                row ++;
            } 
        }
        return false;
    }
};

