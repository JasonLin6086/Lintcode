/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/interleaving-positive-and-negative-numbers
@Language: C++
@Datetime: 15-11-30 01:17
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size==0) return;
        int posCount = 0, negCount = 0;
        
        int i;
        for (i=0; i<size; i++) {
            if (A[i] > 0) posCount ++;
            if (A[i] < 0) negCount ++;
        }
        int posIdx = 1, negIdx = 0;
        if (posCount > negCount) {
            posIdx = 0;
            negIdx = 1;
        }
        while (posIdx < size && negIdx < size) {
            while (posIdx < size && A[posIdx] > 0) {
                posIdx += 2;
            }
            while (negIdx < size && A[negIdx] < 0) {
                negIdx += 2;
            }
            if (posIdx < size && negIdx < size) {
                swap(A[posIdx], A[negIdx]);
            }
        }
    }
};
