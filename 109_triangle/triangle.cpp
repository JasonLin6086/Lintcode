/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 15-12-01 16:17
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int size = triangle.size();
        if (size==0) return 0;
        if (size==1) return triangle[0][0];
        vector<vector<int>> hashmap(triangle);
        int i, j;
        for (i=0; i<size; i++) {
            hashmap[size-1][i] = triangle[size-1][i];
        }
        for (i=size-2; i>=0; i--) {
            for (j=0; j<i+1; j++) {
                triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};

