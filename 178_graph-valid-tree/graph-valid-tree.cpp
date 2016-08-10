/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/graph-valid-tree
@Language: C++
@Datetime: 16-08-02 21:16
*/

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() != n-1) return false;
        vector<int> label;
        for (int i=0; i<n; i++) {
            label.push_back(i);
        }
        for (int i=0; i<edges.size(); i++) {
            label[getFather(label,edges[i][0])] = getFather(label,edges[i][1]);
        }
        for (int i=0; i<n; i++) {
            if (getFather(label, i) != getFather(label, 0)) return false;
        }
        return true;
    }
private:
    int getFather(vector<int>&label, int i) {
        if (label[i] != i) label[i] = getFather(label, label[i]);
        return label[i];
    }
};