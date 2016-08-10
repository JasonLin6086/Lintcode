/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/word-search
@Language: C++
@Datetime: 15-12-07 21:35
*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int row = board.size();
        if (row == 0) return false;
        int col = board[0].size();
        if (col == 0) return false;
        if (word.size() == 0) return true;
        int i, j;
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                bool res = helper(board, word, i, j, 0);
                if (res) return true;
            }
        }
        return false;
    }
private:
    bool helper(vector<vector<char>>&board, string word, int row, int col, int pos) {
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()) {
            return false;
        }
        else if (board[row][col] == (char)word[pos]) {
            if (word.size()-1 == pos) return true;
            board[row][col] = ' ';
            bool rst = helper(board, word, row+1, col, pos+1) ||
                   helper(board, word, row-1, col, pos+1) ||
                   helper(board, word, row, col+1, pos+1) ||
                   helper(board, word, row, col-1, pos+1);
            if (rst) {
                return true;
            } else {
                board[row][col] = (char)word[pos];
            }
        }
        return false;  
    }
};