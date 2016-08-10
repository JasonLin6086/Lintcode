/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 16-06-30 01:43
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        int size = lists.size();
        if (size==0) return NULL;
        if (size==1) return lists[0];
        ListNode * result = helper(lists,0,size-1);
        return result;
    }
private:
    ListNode * helper(vector<ListNode*>lists, int start, int end) {
        if (start==end) return lists[start];
        int mid = start + (end - start) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid+1, end);
        return mergeLists(left, right);
    }
    
    ListNode * mergeLists(ListNode* l, ListNode* r) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while (l!=NULL && r!=NULL) {
            if (l->val < r->val) {
                current->next = l;
                l = l->next;
            } else {
                current->next = r;
                r = r->next;
            }
            current = current->next;
        }
        if (l!=NULL) {
            current->next = l;
        } else {
            current->next = r;
        }
        return dummy->next;
    }
};


