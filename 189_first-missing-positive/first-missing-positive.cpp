/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: C++
@Datetime: 15-09-04 06:15
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int size=A.size();
        int i;
        for (i=0; i<size; i++) {
            while (A[i]>0 && A[i]<=size && (A[i]!=A[A[i]-1])) {
                int tmpInt = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = tmpInt;
            }
        }
        for (i=0; i<size; i++) {
            if (A[i]!=i+1) return i+1;
        }
        return size+1;
    }
};
