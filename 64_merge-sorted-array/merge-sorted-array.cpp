/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-07-14 17:42
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        while(n){
            if(!m || A[m-1] <= B[n-1]) {
                A[m+n-1] = B[n-1];
                n--;
            } else {
                A[m+n-1] = A[m-1];
                m--;
            }
        }
    }
};
