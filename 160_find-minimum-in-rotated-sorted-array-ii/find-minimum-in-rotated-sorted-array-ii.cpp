/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 15-09-21 16:41
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int size = num.size();
        if (size==0) return -1;
        if (size==1) return num[0];
        int start = 0, end = size-1, mid;
        while (start + 1 < end) {
            mid = start + (end - start)/2;
            if (num[mid] < num[end]) {
                end = mid;
            } else if (num[mid] > num[end]) {
                start = mid;
            } else {
                end --;
            }
        }
        if (num[start] < num[end]) return num[start];
        else return num[end];
    }
};
