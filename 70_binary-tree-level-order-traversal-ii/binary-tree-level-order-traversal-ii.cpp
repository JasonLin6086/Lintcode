/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
@Language: C++
@Datetime: 15-09-22 01:35
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int a;
        while (!q.empty()) {
            vector<int> list;
            int size = q.size();
            for (a=0; a<size; a++) {
                TreeNode * node = q.front();
                q.pop();
                list.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(list);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
