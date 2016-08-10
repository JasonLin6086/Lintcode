/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 15-12-01 18:10
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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode * nthNode = head;
        int i;
        for (i=0; i<n; i++) {
            if (nthNode == NULL) return NULL;
            nthNode = nthNode->next;
        }
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * preNode = dummy,
                 * currNode = head;
        while (nthNode != NULL) {
            preNode = preNode->next;
            currNode = currNode->next;
            nthNode = nthNode->next;
        }
        preNode->next = currNode->next;
        free(currNode);
        return dummy->next;
    }
};


