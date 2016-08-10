/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-07-13 16:40
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> stk;
        vector<int> result;
        if (!root) return result;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode * node = stk.top();
            result.push_back(node->val);
            stk.pop();
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
