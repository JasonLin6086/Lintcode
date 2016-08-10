/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 16-08-04 19:14
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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> stk;
        if (!root) return result;
        while (!stk.empty() || root) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                TreeNode * node = stk.top();
                stk.pop();
                result.push_back(node->val);
                root = node->right;
            }
        }
        return result;
        /*
        while (true) {
            while (root) {stk.push(root); root = root->left;}
            if (stk.empty()) break;
            TreeNode* node = stk.top(); stk.pop();
            result.push_back(node->val);
            root = node->right;
        }
        return result;
        */
    }
};