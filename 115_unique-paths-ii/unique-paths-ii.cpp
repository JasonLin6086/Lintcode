/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 15-10-19 21:53
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if (obstacleGrid.empty()||obstacleGrid[0].empty()) return 0;
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        vector<vector<int>> result(M,vector<int>(N,0));
        int i, j;
        for (i=0; i<M; i++) {
            if (obstacleGrid[i][0]) {
                break;
            } else {
                result[i][0] = 1;
            }
        }
        for (i=0; i<N; i++) {
            if (obstacleGrid[0][i]) {
                break;
            } else {
                result[0][i] = 1;
            }
        }
        for (i=1; i<M; i++) {
            for (j=1; j<N; j++) {
                if (obstacleGrid[i][j]) {
                    result[i][j] = 0;
                } else {
                    result[i][j] = result[i-1][j] + result[i][j-1];
                }
            }
        }
        return result[M-1][N-1];
    }
};
