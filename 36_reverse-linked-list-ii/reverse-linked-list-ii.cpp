/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/reverse-linked-list-ii
@Language: C++
@Datetime: 15-09-26 00:43
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head==NULL) return NULL;
        int i;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * node = dummy;
        for (i=1; i<m; i++) {
            if (node==NULL) return NULL;
            node = node->next;
        }
        ListNode * preMNode = node;
        ListNode * mNode = node->next;
        ListNode * nNode = mNode;
        ListNode * postNNode = nNode->next;
        for (i=m; i<n; i++) {
            if (postNNode==NULL) return NULL;
            ListNode * tmpNode = postNNode->next;
            //mNode->next = postNNode->next;
            postNNode->next = nNode;
            nNode = postNNode;
            postNNode = tmpNode;
        }
        preMNode->next = nNode;
        mNode->next = postNNode;
        return dummy->next;
    }
};

