/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 16-07-18 16:35
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int val = INFINITY;
        while (head) {
            if (head->val != val) {
                curr->next = head;
                curr = head;
                val = head->val;
            }
            head = head->next;
        }
        curr->next = NULL;
        return dummy->next;
    }
};