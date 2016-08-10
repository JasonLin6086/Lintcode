/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/clone-graph
@Language: C++
@Datetime: 15-11-07 16:58
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node==NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        return cloneGraphHelper(node, visited);
    }
private:
    UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> & v) {
        if (v[node]) {
            return v[node];
        }
        UndirectedGraphNode * copyNode = new UndirectedGraphNode(node->label);
        v[node] = copyNode;
        int i;
        vector<UndirectedGraphNode *> nbs = node->neighbors;
        for (i=0; i<nbs.size(); i++) {
            copyNode->neighbors.push_back(cloneGraphHelper(nbs[i],v));
        }
        return copyNode;
    }
};
