/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: C++
@Datetime: 16-07-17 16:47
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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if (n==0 || head==NULL) return head;
        ListNode *curt = head;
        int i;
        for (i=0; i<n; i++) {
            if (curt==NULL) {
                return curt;
            }
            //cout<<curt->val<<"--"<<endl;
            curt = curt->next;
        }
        //cout<<curt->val<<endl;
        while (head!=NULL && curt!=NULL) {
            head = head->next;
            curt = curt->next;
        }
        return head;
    }
};



