/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-01-28 23:18
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        vector<long long> result;
        if (size == 0) return result;
        vector<long long> left(size,1), right(size,1);
        int i;
        for (i=1; i<size; i++) {
            right[i] = right[i-1] * nums[i-1];
        }
        for (i=size-2; i>=0; i--) {
            left[i] = left[i+1] * nums[i+1];
        }
        for (i=0; i<size; i++) {
            long long rst = left[i] * right[i];
            result.push_back(rst);
        }
        return result;
    }
};