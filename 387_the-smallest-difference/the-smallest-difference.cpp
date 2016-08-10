/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/the-smallest-difference
@Language: C++
@Datetime: 16-08-10 07:04
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int p1 = 0, p2 = 0;
        int res = INT_MAX;
        while (p1 < A.size() && p2 < B.size()) {
            /*
            res = min(res, abs(A[p1] - B[p2]));
            if (A[p1] <= B[p2]) {
                p1++;
            } else {
                p2++;
            }
            */
            
            if (A[p1]<=B[p2]) {
                res = min(res, B[p2] - A[p1++]);
                if (p1< A.size() && A[p1] > B[p2] && A[p1] - B[p2] < res) {
                    res = min(res, A[p1] - B[p2]);
                }
            } else {
                res = min(res, A[p1] - B[p2++]);
                if (p2 < B.size() && B[p2] > A[p1] && B[p2] - A[p1] < res) {
                    res = min(res, B[p2] - A[p1]);
                }
            }
            
        }
        return res;
    }
};
