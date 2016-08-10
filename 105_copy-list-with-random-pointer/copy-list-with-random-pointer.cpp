/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 15-09-09 21:06
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode*currNode=head;
        while(currNode!=NULL) {
            RandomListNode* newNode = new RandomListNode(currNode->label);
            RandomListNode *nextOriNode = currNode->next;
            currNode->next = newNode;
            newNode->next = nextOriNode;
            currNode = currNode->next->next;
        }
        currNode=head;
        while(currNode!=NULL) {
            if (currNode->random != NULL) {
                currNode->next->random = currNode->random->next;
            }
            currNode=currNode->next->next;
        }
        currNode=head;
        RandomListNode*newHead=currNode->next;
        
        while(currNode!=NULL) {
            RandomListNode*newNode=currNode->next;
            //currNode->next=currNode->next->next;
            currNode=currNode->next->next;
            if (newNode->next!=NULL) {
                newNode->next=newNode->next->next;
            }
        }
        return newHead;
    }
};
