/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/binary-search-tree-iterator
@Language: C++
@Datetime: 16-01-28 19:56
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
    void insertAllNodes(TreeNode* root) {
        while (root!=NULL) {
            stk.push(root);
            root = root->left;
        }
    }
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        insertAllNodes(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !stk.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        if (!stk.empty()) {
            TreeNode * node = stk.top();
            stk.pop();
            if (node->right != NULL) {
                insertAllNodes(node->right);
            }
            return node;
        }
    }
};