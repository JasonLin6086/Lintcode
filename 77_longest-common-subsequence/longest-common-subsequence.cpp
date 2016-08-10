/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 16-01-27 17:44
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.size() < B.size()) {
            return longestCommonSubsequence(B, A);
        }
        int sizeA = A.size(), sizeB = B.size();
        vector<vector<int>> table(2,vector<int>(sizeA+1,0));
        int i, j;
        for (i=1; i<sizeA+1; i++) {
            for (j=1; j<sizeB+1; j++) {
                if (A[i-1] != B[j-1]) {
                    table[i%2][j] = max(table[(i-1)%2][j], table[i%2][j-1]);
                } else {
                    table[i%2][j] = table[(i-1)%2][j-1] + 1;
                }
            }
        }
        return table[sizeA%2][sizeB];
    }
};
