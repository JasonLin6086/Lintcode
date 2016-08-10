/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-07-21 17:42
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int size = A.size();
        if (size==0) return 0;
        if (target < A[0]) return 0;
        if (target > A[size-1]) return size;
        int left=0, right=size-1, mid;
        while (left <= right) {
            mid = (right + left) / 2;
            if (A[mid] == target) return mid;
            if (mid >= 1 && target < A[mid] && target > A[mid-1]) return mid;
            if (A[mid] > target) right = mid - 1;
            else left = mid + 1;
                
        }
        return left;
        /*
        int i, size = A.size();
        if (size==0) return 0;
        if (target < A[0]) return 0;
        if (target > A[size-1]) return size;
        for (i=0; i<size; i++) {
            if (A[i]==target) {
                return i;
            } else if (target > A[i] && (i+1<=size-1 && target < A[i+1])) {
                return i+1;
            }
        }
        return 0;
        */
    }
};
