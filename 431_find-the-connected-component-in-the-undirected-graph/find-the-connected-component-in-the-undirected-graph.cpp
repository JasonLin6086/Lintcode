/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-the-connected-component-in-the-undirected-graph
@Language: C++
@Datetime: 15-10-05 22:13
*/

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
/*        unordered_set<UndirectedGraphNode*> visit;
        vector<vector<int>> res;
        vector<int> path;
        for (auto &n : nodes) {
            if (visit.find(n) == visit.end()) {
                path.clear();
                dfs(nodes, path, visit, n);
                sort(path.begin(), path.end());
                res.push_back(path);
            } 
        }
        return res;
    }
private:
    void dfs(vector<UndirectedGraphNode*> &nodes, vector<int> &path,
            unordered_set<UndirectedGraphNode*> &visit, UndirectedGraphNode* n) {
        visit.insert(n);
        path.push_back(n->label);
        for (auto &nn : n->neighbors) {
            if (visit.find(nn) == visit.end()) {
             dfs(nodes, path, visit, nn);
            }
        }
*/
        unordered_set<UndirectedGraphNode*> visit;
        vector<vector<int>> res;
        vector<int> path;
        queue<UndirectedGraphNode*> que;
        for (auto &n : nodes) {
            if (visit.find(n) == visit.end()) {
                path.clear();
                visit.insert(n);
                for (que.push(n); !que.empty(); que.pop()) {
                    auto u = que.front();
                    path.push_back(u->label);
                    for (auto nn : u->neighbors) {
                        if (visit.find(nn) == visit.end()) {
                            visit.insert(nn);
                            que.push(nn);
                        }
                    }
                }
                sort(path.begin(), path.end());
                res.push_back(path);
            } 
        }
        return res;
    }
};
