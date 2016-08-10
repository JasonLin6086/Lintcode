/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: C++
@Datetime: 15-09-13 01:07
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        int size=S.size();
        vector<int> list;
        vector<int> source(S);
        vector<vector<int>> result;
        sort(source.begin(),source.end());
        helper(source,0,list,result);
        return result;
    }
private:
    void helper(vector<int> &S, int start, vector<int> &lst, vector<vector<int>> &rst) {
        rst.push_back(lst);
        for (int i=start; i<S.size(); i++) {
            if (i!=start && S[i-1]==S[i]) continue;
            lst.push_back(S[i]);
            helper(S,i+1,lst,rst);
            lst.pop_back();
        }
    }
};

