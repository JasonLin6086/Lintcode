/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/k-sum-ii
@Language: C++
@Datetime: 15-11-04 16:16
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<int> list;
        vector<vector<int>> result;
        int start = 0;
        helper(A, k, target, start, list, result);
        return result;
    }
private:
    void helper(vector<int> A, int k, int target, int st, vector<int> &l, vector<vector<int>> &rst) {
        if (l.size()==k) {
            if (0==target) {
                rst.push_back(l);
            }
            return;
        }
        int i;
        for (i=st; i<A.size(); i++) {
            l.push_back(A[i]);
            helper(A,k,target-A[i],i+1,l,rst);
            l.pop_back();
        }
    }
};

