/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 16-08-02 20:29
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int low = 0;
        int high = A.size()-1;
        
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(A[mid] < A[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
