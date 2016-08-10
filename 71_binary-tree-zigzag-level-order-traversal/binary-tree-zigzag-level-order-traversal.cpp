/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: C++
@Datetime: 15-09-23 06:38
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int i;
        vector<int> list;
        int flip = 1;
        while (!q.empty()) {
            int size = q.size();
            list.clear();
            for (i=0; i<size; i++) {
                TreeNode * node = q.front();
                q.pop();
                list.push_back(node->val);
            
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (flip%2 == 0) {
                reverse(list.begin(), list.end());
                flip = 1;
            } else {
                flip = 0;
            }
            result.push_back(list);
        }
        return result;
    }
};
