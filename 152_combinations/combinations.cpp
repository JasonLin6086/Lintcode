/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/combinations
@Language: C++
@Datetime: 15-09-12 17:22
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<int> list;
        vector<vector<int>> result;
        //if (k>n) return result;
        int start = 1;
        helper(n, k, start, list, result);
        return result;
    }
private:
    void helper(int n, int k, int s, vector<int> &lst, vector<vector<int>> &rst) {
        if (lst.size()==k) {
            rst.push_back(lst);
            return;
        }
        for (int i=s; i<=n && k-lst.size()<=n-i+1; i++) {
            lst.push_back(i);
            helper(n,k,i+1,lst,rst);
            lst.pop_back();
        }
    }
};
