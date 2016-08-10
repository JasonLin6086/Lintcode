/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/convert-sorted-list-to-balanced-bst
@Language: C++
@Datetime: 15-09-09 20:43
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (head==NULL) return NULL;
        int length=0;
        ListNode*currNode=head;
        while(currNode!=NULL) {
            length++;
            currNode=currNode->next;
        }
        return buildBST(head, length);
    }
private:
    TreeNode * buildBST(ListNode*h, int l) {
        if (h==NULL||l<=0) return NULL;
        ListNode* rightList = h;
        int count=0;
        while (count < l/2) {
            rightList=rightList->next;
            count++;
        }
        TreeNode* left = buildBST(h, l/2);
        TreeNode* right = buildBST(rightList->next, l-1-l/2);
        TreeNode* newNode = new TreeNode(rightList->val);
        newNode->left = left;
        newNode->right = right;
        return newNode;
    }
};



