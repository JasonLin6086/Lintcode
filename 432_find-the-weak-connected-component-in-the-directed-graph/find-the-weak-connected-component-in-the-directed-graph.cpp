/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/find-the-weak-connected-component-in-the-directed-graph
@Language: C++
@Datetime: 15-10-06 20:15
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        // Time:  O(nlogn)
        // Space: O(n)
        unordered_map<int, int> father;
        int fa, fb, fn;
        for (auto &n : nodes) {
            for (auto &nn : n->neighbors) {
                fa = find(father, n->label);
                fb = find(father, nn->label);
                if (fa != fb) {
                    if (fa > fb) father[fa] = fb;
                    else father[fb] = fa;
                }
            }
        }
        unordered_map<int, vector<int>> comp;
        for (auto &n : nodes) {
            fn = find(father, n->label);
            comp[fn].push_back(n->label);
        }
        vector<vector<int>> res;
        for (auto &c : comp) {
            sort(c.second.begin(), c.second.end());
            res.push_back(c.second);
        }
        return res;
    }
private:
    int find(unordered_map<int, int> &father, int x) {
        if (father.find(x) == father.end()) {
            father[x] = x;
            return x;
        }
        while (x != father[x]) x = father[x];
        return x;
    }
};
