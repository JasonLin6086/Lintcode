/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/segment-tree-query
@Language: C++
@Datetime: 15-12-08 07:35
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(start == root->start && root->end == end) {
            return root->max;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        
        int leftmax = INT_MIN, rightmax = INT_MIN;
        // left
        if(start <= mid) {
            if(mid < end) { 
                leftmax =  query(root->left, start, mid);
            } else {  
                leftmax = query(root->left, start, end);
            }
        }
        // right
        if(mid < end) { 
            if(start <= mid) {
                rightmax = query(root->right, mid+1, end);
            } else {  
                rightmax = query(root->right, start, end);
            }
        }  
        // 
        return max(leftmax, rightmax);
    }
};