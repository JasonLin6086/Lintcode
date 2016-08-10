/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/combination-sum
@Language: C++
@Datetime: 15-09-12 20:10
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        helper(result, solution, candidates, 0, target);
        return result;
    }
    
    void helper(vector<vector<int>>& result, vector<int>& solution, vector<int>& candidates, int ind, int target){
        if (target<0)
            return;
        if (target==0){
            result.push_back(solution);
            return;
        }
        for (int i=ind; i<candidates.size(); i++){
            solution.push_back(candidates[i]);
            helper(result,solution, candidates, i, target-candidates[i]);
            solution.pop_back();
        }
    }
};
