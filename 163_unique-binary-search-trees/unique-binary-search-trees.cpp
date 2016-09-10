/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees
@Language: C++
@Datetime: 15-09-25 16:43
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> result(n+1);
        int i, j;
        if (n<0) return -1;
        result[0] = 1;
        for (i=1; i<n+1; i++) {
            for (j=0; j<i; j++) {
                result[i] = result[i] + result[j] * result[i-j-1];
            }
        }
        return result[n];
    }
};
