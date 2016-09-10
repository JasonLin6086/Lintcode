/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 16-06-29 20:03
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        long long res = 0;
        vector<int> v;
        for (int i = A.size() - 1; i >= 0; --i) {
            int left = 0, right = v.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (A[i] > v[mid]) left = mid + 1;
                else right = mid;
            }
            v.insert(v.begin() + right, A[i]);
            res += right;
        }
        return res;        
    }
};