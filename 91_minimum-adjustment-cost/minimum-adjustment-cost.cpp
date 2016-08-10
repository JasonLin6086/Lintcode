/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/minimum-adjustment-cost
@Language: C++
@Datetime: 16-08-10 06:51
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        vector<vector<int>> res(A.size()+1, vector<int>(100));
        for (int j=0; j<=99; j++) {
            res[0][j] = 0;
        }
        for (int i=1; i<=A.size(); i++) {
            for (int j=0; j<=99; j++) {
                res[i][j] = INT_MAX;
                int lowerRange = max(0, j-target);
                int upperRange = min(99, j+target);
                for (int p=lowerRange; p<=upperRange; p++) {
                    res[i][j] = min(res[i][j], res[i-1][p]+abs(j-A[i-1]));
                }
            }
        }
        int result = INT_MAX;
        for (int j=0; j<=99; j++) {
            result = min(result, res[A.size()][j]);
        }
        return result;
    }
};