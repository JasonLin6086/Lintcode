/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-07-13 16:39
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> stk;
        vector<int> result;
        if (!root) return result;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode * node = stk.top();
            result.push_back(node->val);
            stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return result;
    }
};
