/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 15-08-04 23:23
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return (-1 != maxDepth(root));
    }
private:
    int maxDepth(TreeNode *root) {
        if (root==NULL) {
            return 0;
        }
        int lMax = maxDepth(root->left);
        int rMax = maxDepth(root->right);
        if (lMax==-1 || rMax==-1 || abs(lMax-rMax) > 1) {
            return -1;
        }
        return max(lMax, rMax) + 1;
    }
};
