/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/palindrome-linked-list
@Language: C++
@Datetime: 16-08-10 18:51
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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (head == NULL || head->next == NULL) return true;
        ListNode *fast, *slow;
        fast = slow = head;
        //split in the middle, then reverse
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * reverseHead = reverse(slow);
        while (reverseHead != NULL) {
            if (head->val != reverseHead->val) {
                return false;
            }
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
private:
    ListNode * reverse(ListNode * head) {
        ListNode * preNode = NULL;
        while (head != NULL) {
            ListNode * nextNode = head->next;
            head->next = preNode;
            preNode = head;
            head = nextNode;
        }
        return preNode;
    }
};