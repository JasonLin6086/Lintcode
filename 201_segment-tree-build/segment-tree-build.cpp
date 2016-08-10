/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/segment-tree-build
@Language: C++
@Datetime: 15-12-08 07:23
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end) {  // check core case
            return NULL;
        }
       
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
       
        if(start != end) {
            int mid = start + (end - start) / 2;
            root->left = build(start, mid);
            root->right = build(mid+1, end);
        }
        return root;
    }
};