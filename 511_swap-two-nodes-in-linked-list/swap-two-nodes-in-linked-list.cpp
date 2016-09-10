/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/swap-two-nodes-in-linked-list
@Language: C++
@Datetime: 16-03-15 02:05
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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * current = dummy;
        while (current->next!=NULL) {
            if (current->next->val == v1 || current->next->val == v2) {
                int foundVal = (current->next->val == v1) ? v1 : v2;
                int nextVal = (foundVal == v1) ? v2 : v1;
                ListNode * v1node = current->next;
                ListNode * prev2node = current->next;
                while (prev2node->next!=NULL && prev2node->next->val != nextVal) {
                    prev2node = prev2node->next;
                }
                if (prev2node->next==NULL || prev2node->next->val != nextVal) return dummy->next;
                ListNode * v2node, * v1next, * v2next;
                
                    v2node = prev2node->next;
                    v1next = v1node->next;
                    v2next = v2node->next;
                    current->next = v2node;
                    if (prev2node->val == foundVal) {
                        v2node->next = v1node;
                    } else {
                        prev2node->next = v1node;
                        v2node->next = v1next;
                    }
                    v1node->next = v2next;

                return dummy->next;
            }
            current = current->next;
        }
        return dummy->next;
    }
};