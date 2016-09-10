/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-08-11 18:58
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int start = 0, end = num.size()-1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (num[mid] > num[end]) {
                start = mid + 1;
            } else if (num[mid] < num[end]) {
                end = mid;
            } else {
                end --;
            }
        }
        return num[start];
    }
};
