/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: C++
@Datetime: 16-07-23 20:31
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next!=NULL && head->next->next!=NULL) {
            ListNode * n1 = head->next, * n2 = head->next->next;
            head->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            head = n1;
        }
        return dummy->next;
        /* wrong
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        ListNode *firstNode = head;
        ListNode *secondNode = head->next;
        while (firstNode != NULL && secondNode != NULL) {
            ListNode *  nextSecondNode = secondNode->next;
            firstNode->next = nextSecondNode;
            secondNode->next = firstNode;
            firstNode = nextSecondNode;
            secondNode = firstNode->next;
        }
        return head;
        */
    }
};
