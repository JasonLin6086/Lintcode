/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/combination-sum-ii
@Language: C++
@Datetime: 15-11-07 17:16
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<int> list;
        vector<vector<int>> rst;
        sort(num.begin(),num.end());
        comnbinatonSum2Helper(num,target,list,rst,0);
        return rst;
    }
private:
    void comnbinatonSum2Helper(vector<int> &num, int target, vector<int> &l, vector<vector<int>> &rst, int st) {
        if (target==0) {
            rst.push_back(l);
            return;
        }
        int i;
        for (i=st; i<num.size(); i++) {
            if (i!=st && num[i]==num[i-1]) continue;
            if (target-num[i] < 0) return;
            l.push_back(num[i]);
            comnbinatonSum2Helper(num,target-num[i],l,rst,i+1);
            l.pop_back();
        }
    }
};
