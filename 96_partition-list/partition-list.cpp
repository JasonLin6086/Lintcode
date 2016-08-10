/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-07-17 17:41
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if (head==NULL) return NULL;
        ListNode*leftDummy=new ListNode(0);
        ListNode*rightDummy=new ListNode(0);
        ListNode*left=leftDummy;
        ListNode*right=rightDummy;
        while (head!=NULL) {
            //cout<<head->val<<endl;
            if (head->val<x) {
                //cout<<"left:"<<head->val<<endl;
                left->next=head;
                left=left->next;
            } else {
                //cout<<"right:"<<head->val<<endl;
                right->next=head;
                right=right->next;
            }
            head=head->next;
        }
        right->next=NULL;
        left->next=rightDummy->next;
        return leftDummy->next;
    }
};



