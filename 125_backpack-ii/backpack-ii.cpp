/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/backpack-ii
@Language: C++
@Datetime: 15-10-19 21:17
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        const int N = A.size() + 1;
        const int M = m + 1;
        vector<vector<int> > result(N,vector<int>(M));

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j < A[i - 1]) {
                    result[i][j] = result[i - 1][j];
                } else {
                    int temp = result[i - 1][j - A[i - 1]] + V[i - 1];
                    result[i][j] = max(temp, result[i - 1][j]);
                }
            }
        }

        return result[N - 1][M - 1];
    }
};
