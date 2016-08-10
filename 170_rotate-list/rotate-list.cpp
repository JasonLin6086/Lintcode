/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 15-09-09 16:40
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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (head==NULL) return NULL;
        if (k==0||head->next==NULL) return head;
        int size = 0;
        ListNode*pointer=head;
        while (pointer!=NULL) {
            size++;
            pointer=pointer->next;
        }
        k = k%size;
        ListNode*right=head;
        while(k>0) {
            right=right->next;
            k--;
        }
        ListNode*left=head;
        while(right->next!=NULL) {
            left=left->next;
            right=right->next;
        }
        right->next=head;
        ListNode*newHead=left->next;
        left->next=NULL;
        return newHead;
    }
};
