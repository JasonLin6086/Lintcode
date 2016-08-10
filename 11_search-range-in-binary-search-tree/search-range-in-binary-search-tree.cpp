/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: C++
@Datetime: 15-09-11 04:28
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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> result;
        if (root==NULL) return result;
        searchRange(root,k1,k2,result);
        return result;
    }
private:
    void searchRange(TreeNode*root, int k1, int k2, vector<int>&result) {
            if (root->left) searchRange(root->left,k1,k2,result);
            if (root->val>=k1 && root->val<=k2) result.push_back(root->val);
            if (root->right) searchRange(root->right,k1,k2,result);
    }
};
