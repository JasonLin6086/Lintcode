/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii
@Language: C++
@Datetime: 15-09-24 20:57
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *currNode = dummy;
        while (currNode->next!=NULL && currNode->next->next!=NULL) {
            if (currNode->next->val == currNode->next->next->val) {
                int tmpVal = currNode->next->val;
                while (currNode->next!=NULL && currNode->next->val == tmpVal) {
                    currNode->next = currNode->next->next;
                }
            } else {
                currNode = currNode->next;
            }
        }
        
        return dummy->next;
    }
};
