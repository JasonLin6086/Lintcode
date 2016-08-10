/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/binary-tree-maximum-path-sum
@Language: C++
@Datetime: 15-11-07 16:35
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
private: 
    int maxVal = INT_MIN;
    int maxPathSumHelper(TreeNode *root) {
        if (root==NULL) return 0;

        int left = max(0, maxPathSumHelper(root->left));
        int right = max(0, maxPathSumHelper(root->right));
        maxVal = max(maxVal, root->val + left + right);
        
        return root->val + max(left, right);        
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        maxPathSumHelper(root);
        return maxVal;
    }
};
