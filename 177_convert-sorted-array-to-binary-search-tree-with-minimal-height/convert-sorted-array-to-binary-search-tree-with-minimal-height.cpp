/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: C++
@Datetime: 15-09-26 16:31
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size == 0) return NULL;
        if (size == 1) {
            TreeNode * node = new TreeNode(A[0]);
            return node;
        }
        return sorteArrayHelper(A, 0, size-1);
    }
private:
    TreeNode *sorteArrayHelper(vector<int> &A, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode * node = new TreeNode(A[mid]);
        TreeNode * left = sorteArrayHelper(A, start, mid - 1);
        TreeNode * right = sorteArrayHelper(A, mid + 1, end);
        node->left = left;
        node->right = right;
        return node;
    }
};



