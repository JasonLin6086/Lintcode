/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 15-09-28 21:36
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        int i, j, count=0;
        vector<vector<bool>> marked(row,vector<bool>(col,false));
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                if (grid[i][j] && !marked[i][j]) {
                    helper(grid, i, j, marked);
                    count++;
                }
            }
        }
        return count;
    }
private:
	void helper(vector<vector<bool>>& grid, int r, int c, vector<vector<bool>> &m) {
	    if (r<0 || r>m.size()-1 || c<0 || c>m[0].size()-1) return;
	    if (!grid[r][c] || m[r][c]) return;
		m[r][c] = true;
		//vector<pair<int, int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		helper(grid, r+1, c, m);
        helper(grid, r-1, c, m);
        helper(grid, r, c+1, m);
        helper(grid, r, c-1, m);
	}
};
