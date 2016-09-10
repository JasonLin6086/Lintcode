/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees-ii
@Language: C++
@Datetime: 16-08-10 18:17
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return helper(0, n-1);
    }
private:
    vector<TreeNode*> helper(int from, int to) {
        vector<TreeNode*> result;
        if (to < from) result.push_back(NULL);
        for (int i=from; i<=to; i++) {
            vector<TreeNode*> left = helper(from, i-1);
            vector<TreeNode*> right = helper(i+1, to);
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    TreeNode* root = new TreeNode(i + 1);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};