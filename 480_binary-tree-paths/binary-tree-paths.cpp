/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 15-11-29 07:08
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> rst;
        helper(root, rst);
        return rst;
    }
private:
    deque<int> que;
    void helper(TreeNode* root, vector<string> &rst) {
        if (root==NULL) return;
        if (root->left==NULL && root->right==NULL) {
            string path = "";
            for (auto it=que.begin(); it!=que.end(); it++) {
                 path += to_string(*it) + "->";
            }
            path += to_string(root->val);
            rst.push_back(path);
            return;
        }
        que.push_back(root->val);
        helper(root->left, rst);
        helper(root->right, rst);
        que.pop_back();
    }
};
