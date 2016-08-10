/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/segment-tree-query-ii
@Language: C++
@Datetime: 15-12-08 07:38
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(start > end || root == NULL)
            return 0;
        if(start <= root->start && root->end <= end) { 
            return root->count;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        int leftsum = 0, rightsum = 0;
        // left
        if(start <= mid) {
            if(mid < end) { 
                leftsum =  query(root->left, start, mid);
            } else { 
                leftsum = query(root->left, start, end);
            }
        }
        // right
        if(mid < end) {
            if(start <= mid) {
                rightsum = query(root->right, mid+1, end);
            } else {
                rightsum = query(root->right, start, end);
            } 
        }  
        // 
        return leftsum + rightsum;
    }
};