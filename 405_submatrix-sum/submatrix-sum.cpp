/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/submatrix-sum
@Language: C++
@Datetime: 15-09-28 23:37
*/

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
/*        vector<vector<int>> result;
        int row = matrix.size();
        if (row == 0) return result;
        int col = matrix[0].size();
        if (col == 0) return result;

        int i, j, k;
        vector<vector<int>> sums(row+1, vector<int>(col+1, 0));
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                sums[i+1][j+1] = matrix[i][j]+sums[i+1][j]+sums[i][j+1]-sums[i][j];
            }
        }
        for (i=0; i<row; i++) {
            for (k=i+1; k<=row; k++) {
                unordered_map<int, int> map;
                for (j=0; j<=col; j++) {
                    int diff = sums[k][j]-sums[i][j];
                    if (map[diff]) {
                        int pos = map[diff];
                        result.push_back({i,pos});
                        result.push_back({k-1,j-1});
                        return result;
                    } else {
                        map[diff] = j;
                    }
                }
            }
        }
        return result;*/
        vector<vector<int>> res;
        int m = matrix.size();
        if(0 == m) return res;
        int n = matrix[0].size();

        for(int i=0;i<n;i++) {
            vector<int> sum(m, 0);
            for(int j=i;j<n;j++) {
                
                //sum[k] is the sum of matrix (k,i), (k,j)
                //sum of subarray of sum[k] can be all sub
                //matrix of (0,i), (m-1,j)
                for(int k=0;k<m;k++) 
                    sum[k] += matrix[k][j];
    
                //find a subarray with 0 sum
                int lastSum = 0;
                unordered_map<int, int> set;
                set[0] = -1;
                for(int v=0;v<m;v++) {
                    lastSum += sum[v];
                    if(set.count(lastSum)) {
                        res.push_back(vector<int>({set[lastSum]+1, i}));
                        res.push_back(vector<int>({v, j}));
                        return res;
                    }
                    set[lastSum] = v;
                }
            }
        }
        return res;        
    }
};
