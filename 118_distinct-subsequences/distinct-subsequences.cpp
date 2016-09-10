/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 15-09-14 00:50
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (S.size() < T.size()) return 0;
        if (T.empty()) return 1;

        vector<vector<int> > f(S.size() + 1, vector<int>(T.size() + 1, 0));
        for (int i = 0; i < S.size(); ++i) {
            f[i][0] = 1;
            for (int j = 0; j < T.size(); ++j) {
                if (S[i] == T[j]) {
                    f[i + 1][j + 1] = f[i][j + 1] + f[i][j];
                } else {
                    f[i + 1][j + 1] = f[i][j + 1];
                }
            }
        }

        return f[S.size()][T.size()];    
    }
};

