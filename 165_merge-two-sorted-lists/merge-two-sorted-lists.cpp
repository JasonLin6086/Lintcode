/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 15-09-09 05:50
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        ListNode *current=dummy;

        while (l1!=NULL && l2!=NULL) {
            if (l1->val < l2->val) {
                current->next=l1;
                l1 = l1->next;
            } else {
                current->next=l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1!=NULL) current->next = l1;
        if (l2!=NULL) current->next = l2;
        return dummy->next;
    }
};
