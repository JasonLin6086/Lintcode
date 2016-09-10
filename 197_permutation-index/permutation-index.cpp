/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: C++
@Datetime: 15-10-06 19:50
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        // index = 2! * (2 - 1) + 1! * (3 - 1) + 0! * (1 - 1) + 1
        int size = A.size();
        if (size==0) return 0;
        int i, j;
        long long index = 1;
        long long factor = 1;
        for (i=size-1; i>=0; i--) {
            int rank = 0;
            for (j=i+1; j<size; j++) {
                if (A[i] > A[j]) rank++;
            }
            index = index + rank * factor;
            factor = factor * (size-i);
        }
        return index;
    }
};
