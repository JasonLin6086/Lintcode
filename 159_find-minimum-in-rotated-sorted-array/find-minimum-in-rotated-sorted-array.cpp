/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: C++
@Datetime: 16-08-11 18:52
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int start = 0, end = num.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (num[mid] > num[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return num[start];
    }
};
