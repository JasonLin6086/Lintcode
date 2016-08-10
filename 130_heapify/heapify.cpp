/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/heapify
@Language: C++
@Datetime: 15-11-04 16:35
*/

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size<=1) return;
        int i;
        for (i=size/2-1; i>=0; i--) {
            heapifyHelper(A, i);
        }
    }
private:
    void heapifyHelper(vector<int> &A, int pos) {
        int left = 2*pos+1 >= A.size() ? INT_MAX : A[2*pos+1];
        int right = 2*pos+2 >= A.size() ? INT_MAX : A[2*pos+2];
        if (left<right && left<A[pos]) {
            A[2*pos+1] = A[pos];
            A[pos] = left;
            heapifyHelper(A,2*pos+1);
        } else if (right<A[pos]) {
            A[2*pos+2] = A[pos];
            A[pos] = right;
            heapifyHelper(A,2*pos+2);
        }
    }
};
