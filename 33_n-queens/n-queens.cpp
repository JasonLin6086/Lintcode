/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/n-queens
@Language: C++
@Datetime: 15-09-13 00:48
*/

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    bool isOK(vector<string> &v, int n, int x, int y) {
        for (int i = 0; i < x; ++i) 
            if (v[i][y] == 'Q') return false;
        for (int i = 1; x - i >= 0 && y - i >= 0; ++i) 
            if (v[x-i][y-i] == 'Q') return false;
        for (int i = 1; x - i >= 0 && y + i < n; ++i)
            if (v[x-i][y+i] == 'Q') return false;
        return true;
    }
    void dfs(vector<vector<string>> &res, vector<string> &v, int n, int idx) {
        if (idx == n) {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < n; ++i) {
            v[idx][i] = 'Q';
            if (isOK(v, n, idx, i)) dfs(res, v, n, idx + 1);
            v[idx][i] = '.';
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> res;
        string s;
        for (int i = 0; i < n; ++i) s.push_back('.');
        vector<string> v(n, s);
        dfs(res, v, n, 0);
        return res;
    }
};

