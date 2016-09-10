/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 15-07-23 06:54
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        int i=sizeA-1, j=sizeB-1;
        int index = sizeA+sizeB-1;
        A.resize(index+1);
        
        while (i>=0 && j>=0) {
            if (A[i] > B[j]) {
                A[index] = A[i];
                i--;
                index--;
            } else {
                A[index] = B[j];
                j--;
                index--;
            }
        }
        while (i>=0) {
            A[index] = A[i];
            i--;
            index--;
        }
        while (j>=0) {
            A[index] = B[j];
            j--;
            index--;
        }
        
        return A;
    }
};
