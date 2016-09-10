/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/segment-tree-modify
@Language: C++
@Datetime: 15-12-08 07:27
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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if(root->start == index && root->end == index) { // found
            root->max = value;
            return;
        }
        
        // find
        int mid = root->start + (root->end - root->start) / 2;
        if(root->start <= index && index <= mid) {
            modify(root->left, index, value);
        }
        
        if(mid < index && index <= root->end) {
            modify(root->right, index, value);
        }
        // update
        root->max = max(root->left->max, root->right->max);
    }
};