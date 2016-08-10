/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 15-12-01 18:25
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int i, idx = 0, n = A.size();
        /*
        for (i=0; i<n; i++) {
            if (A[i]==elem) {
                A[i] = A[n-1];
                i--;
                n--;
            }
        }
        return n;
        */
        for (i=0; i<n; i++) {
            if (A[i] != elem) {
                A[idx] = A[i];
                idx ++;
            } 
        }
        return idx;
    }
};
