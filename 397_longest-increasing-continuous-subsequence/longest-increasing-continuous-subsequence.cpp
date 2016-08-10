/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 15-11-07 03:15
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int size = A.size();
        if (size==0) return 0;
        int i;
        int rst = 1;
        bool fromLeft = true;
        int start = 0;
        /*
        vector<int> result(size);
        result[0] = 1;
        int maxLtoR
        for (i=1; i<size; i++) {
            if (A[i-1] < A[i]) {
                result[i] = result[i-1] + 1;
            } else {
                result[i] = 1;
            }
        }
        int maxLtoR = *max_element(result.begin(),result.end());
        result[0] = 1;
        for (i=1; i<size; i++) {
            if (A[i-1] > A[i]) {
                result[i] = result[i-1] + 1;
            } else {
                result[i] = 1;
            }
        }  
        int maxRtoL = *max_element(result.begin(),result.end());
        return max(maxLtoR,maxRtoL);
        */
        for (i=1; i<size; i++) {
            if (A[i] > A[i-1]) {
                if (fromLeft) {
                    rst = max(rst, i-start+1);
                } else {
                    start = i - 1;
                    fromLeft = true;
                }
            } else if (A[i] < A[i-1]) {
                if (!fromLeft) {
                    rst = max(rst, i-start+1);
                } else {
                    start = i - 1;
                    fromLeft = false;
                }
            }
        }
        return rst;
    }
};
