/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: C++
@Datetime: 15-09-21 17:23
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &in, vector<int> &post) {
        // write your code here
        unordered_map<int, int> in_entry_idx_map;
        for (int i = 0; i < in.size(); ++i) {
            in_entry_idx_map[in[i]] = i;
        }
        return ReconstructPostInOrdersHelper(post, 0, post.size(), in, 0, in.size(),
                                             in_entry_idx_map);
    }

    TreeNode * ReconstructPostInOrdersHelper(vector<int>& post, int post_s, int post_e, vector<int>& in, int in_s, int in_e, unordered_map<int, int>& in_entry_idx_map) 
    {
        if (post_e > post_s && in_e > in_s) {
            int idx = in_entry_idx_map[post[post_e - 1]];
            int left_tree_e = idx - in_s;

            TreeNode *node = new TreeNode(post[post_e - 1]);
            // Recursively builds the left subtree.
            node->left =ReconstructPostInOrdersHelper(
                post, post_s, post_s + left_tree_e, 
                in, in_s, idx, 
                in_entry_idx_map);
            // Recursively builds the right subtree.
            node->right = ReconstructPostInOrdersHelper(
                post, post_s + left_tree_e, post_e - 1, 
                in, idx + 1, in_e, 
                in_entry_idx_map);
            return node;
        }
        return NULL;
    }
};
