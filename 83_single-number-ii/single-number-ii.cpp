/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 15-09-23 06:01
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        int size = A.size();
        int i, a=0;
        for (i=1; i<size; i++) {
            a = A[0] & (a^A[i]);
            A[0] = a | (A[0]^A[i]);
        }
        return A[0];        
    }
};
