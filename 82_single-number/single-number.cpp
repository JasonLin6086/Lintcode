/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 15-09-07 20:23
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        if (A.empty()) return 0;
        int result = A[0];
        int size = A.size();
        int i;
        for (i=1; i<size; i++) {
            result = result ^ A[i];
        }
        return result;
    }
};

