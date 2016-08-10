/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 15-09-28 18:26
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
       int n = A.size();
       if(n == 0) {
            return vector<int>({-1, -1});
        }

        vector<int> v;
        int low = 0;
        int high = n - 1;
        
        while(low + 1 < high) {
            int mid = low + (high - low) / 2;
            if(A[mid] >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (A[low] == target) {
            v.push_back(low);
        } else if (A[high] == target) {
            v.push_back(high);
        } else {
            return vector<int>({-1, -1});
        }

        low = 0;
        high = n - 1;
        
        while(low + 1 < high) {
            int mid = low + (high - low) / 2;
            if(A[mid] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (A[high] == target) {
            v.push_back(high);
        } else if (A[low] == target) {
            v.push_back(low);
        } else {
            return vector<int>({-1, -1});
        }
        
        return v;
    }
};
