/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/reverse-nodes-in-k-group
@Language: C++
@Datetime: 15-10-14 23:42
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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
		if (k == 1) {
			return head;
		}

		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *p1 = dummy, *p2 = dummy;

		for (int i = 0; i < k; i++) {
			if (p2 == NULL) {
				break;
			}
			p2 = p2->next;
		}
		if (p2 == NULL) {
			return head;
		}

		while (p2 != NULL) {
			p2 = reverse(p1, p2);
			for (int i = 0; i < k; i++) {
				if (p2 == NULL) {
					break;
				}
				p1 = p1->next;
				p2 = p2->next;
			}
		}

		return dummy->next;
    }
private:
	ListNode *reverse(ListNode *p1, ListNode *p2) {
		ListNode *p1next = p1->next;
		ListNode *p2next = p2->next;
		ListNode *prev = p2next;
		ListNode *p = p1next;

		while (p != p2next) {
			ListNode *temp = p->next;
			p->next = prev;
			prev = p;
			p = temp;
		}
		p1->next = p2;
		return p1next;
	}
};
