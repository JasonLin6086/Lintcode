/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-01-28 23:03
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int start=0, end=A.size()-1, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (target == A[mid]) return true;
            if (A[mid] < A[end]) {
                if (target > A[mid] && target <= A[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (A[mid] > A[end]) {
                if (target >= A[start] && target < A[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                end --;
            }
        }
        return false;
    }
};