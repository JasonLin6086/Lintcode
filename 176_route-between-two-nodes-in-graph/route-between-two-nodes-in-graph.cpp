/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/route-between-two-nodes-in-graph
@Language: C++
@Datetime: 15-12-08 07:19
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
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_set<DirectedGraphNode *> visited_node;
        visited_node.insert(s);
        return BFS(s, t, visited_node);
        //return DFS(s, t, visited_node);
    }
private:
    bool BFS(DirectedGraphNode* s, const DirectedGraphNode* t,
             unordered_set<DirectedGraphNode *> &visited_node) {
        queue<DirectedGraphNode *> q;
        q.push(s);
        while (!q.empty()) {
            s = q.front();
            q.pop();

            if (s->label == t->label) {
                return true;
            }

            // Add neighbors which are not visited into the queue
            for (auto node: s->neighbors) {
                if (visited_node.insert(node).second) {
                    q.push(node);
                }
            }
        }
        return false;
    }
    bool DFS(DirectedGraphNode* s, const DirectedGraphNode* t,
             unordered_set<DirectedGraphNode *> &visited_node) {
        if (s->label == t->label) {
            return true;
        }

        // Search neighbors which are not visted
        for (auto node: s->neighbors) {
            if (visited_node.insert(node).second) {
                if (DFS(node, t, visited_node)) {
                    return true;
                }
            }
        }
        return false;
    }
};

