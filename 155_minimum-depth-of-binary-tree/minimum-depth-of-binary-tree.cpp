/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/minimum-depth-of-binary-tree
@Language: C++
@Datetime: 16-07-15 16:22
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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        if (!root->left && !root->right) {
            return 1;
        }
        int lmin = minDepth(root->left);
        int rmin = minDepth(root->right);
        if (lmin == 0) lmin = INT_MAX;
        else if (rmin == 0) rmin = INT_MAX;
        return min(lmin, rmin) + 1;
    }
};