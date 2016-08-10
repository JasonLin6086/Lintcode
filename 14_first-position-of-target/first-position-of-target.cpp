/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-07-13 18:14
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int size=array.size();
        int start=0, end=size-1, mid;
        while (start<=end) {
            mid = start + (end-start) / 2;
            if (array[mid]==target) {
                while (mid > 1 && array[mid-1] == target) mid--;
                return mid;
            }
            if (array[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};
