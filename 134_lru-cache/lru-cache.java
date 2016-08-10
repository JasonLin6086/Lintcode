/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/lru-cache
@Language: Java
@Datetime: 16-03-07 23:53
*/

public class Solution {
    class ListNode {
        int key;
        int val;
        ListNode prev;
        ListNode next;
    }
    private void addNode(ListNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;        
    }
    private void removeNode(ListNode node) {
        ListNode prev = node.prev;
        ListNode next = node.next;
        prev.next = next;
        next.prev = prev;
    }
    private void addToHead(ListNode node) {
        removeNode(node);
        addNode(node);
    }
    private ListNode popTail() {
        ListNode res = tail.prev;
        removeNode(res);
        return res;
    }
    private void printList() {
        ListNode current = head;
        while (current!=null && current.next != null) {
            System.out.print(current.next.val+" ");
            current = current.next;
        }
        System.out.println();
    }
    private int capacity;
    private int count;
    private Map<Integer, ListNode> hash = new HashMap<Integer, ListNode>();
    private ListNode head, tail;
    
    // @param capacity, an integer
    public Solution(int capacity) {
        // write your code here
        this.capacity = capacity;
        this.count = 0;
        head = new ListNode();
        tail = new ListNode();
        head.prev = null;
        head.next = tail;
        tail.prev = head;
        tail.next = null;
    }

    // @return an integer
    public int get(int key) {
        // write your code here
        ListNode node = hash.get(key);
        if (node == null) {
            return -1;
        } else {
            addToHead(node);
            return node.val;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    public void set(int key, int value) {
        // write your code here
        ListNode node = hash.get(key);
        if (node != null) {
            node.val = value;
            addToHead(node);
        } else {
            ListNode newNode = new ListNode();
            newNode.val = value;
            newNode.key = key;
            hash.put(key, newNode);
            this.addNode(newNode);
            this.count ++;
            if (this.count > this.capacity) {
                ListNode tail = this.popTail();
                hash.remove(tail.key);
                this.count --;
            }
        }
    }
}