/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-07-13 16:28
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        //sort(A.begin(), A.end());
        helper(A, 0, A.size()-1);
    }
private:
    void helper(vector<int>&A, int l, int u) {
        if (l > u) return;
        int pivot = l;
        int left = l+1;
        int right = u;
        while (left <= right) {
            while (left<=right && A[left] < A[pivot]) left++;
            while (left<=right && A[right] >= A[pivot]) right--;
            if (left < right)
                swap(A[left], A[right]);
        }
        swap(A[right], A[pivot]);
        helper(A, l, right-1);
        helper(A, right+1, u);
    }
};