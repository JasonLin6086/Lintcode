/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/segment-tree-build-ii
@Language: C++
@Datetime: 15-09-26 21:39
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        int size = A.size();
        return helper(A, 0, size-1);
    }
private:
    SegmentTreeNode * helper(vector<int>&A, int start, int end) {
        if (start > end) return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end, INT_MAX);
        if (start==end) {
            root->max = A[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode * left = helper(A, start, mid);
        SegmentTreeNode * right = helper(A, mid + 1, end);
        root->left = left;
        root->right = right;
        int left_max = root->left != nullptr ? root->left->max : INT_MAX;
        int right_max = root->right != nullptr ? root->right->max : INT_MAX;
        root->max = max(left_max,right_max);
        return root;
    }
};
