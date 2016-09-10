/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/house-robber-iii
@Language: C++
@Datetime: 16-07-13 17:39
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        int val1, val2;
        helper(root, val1, val2);
        return max(val1, val2);
    }
private:
    void helper(TreeNode* root, int &val1, int &val2) {
        val1 = 0, val2 = 0;
        if (!root) return;
        int rl, rr, sl, sr;
        helper(root->left, rl, sl);
        helper(root->right, rr, sr);
        val1 = sl + sr + root->val;
        val2 = max(rl, sl) + max(rr, sr);
    }
};