/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: C++
@Datetime: 15-09-04 22:21
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int size = num.size();
        int i;
        int start=0, end=size-1, mid;
        while (start+1<end) {
            mid = start + (end - start) / 2;
            if (num[mid] > num[end])
                start = mid;
            else 
                end = mid;
        }
        if (num[start] > num[end])
            return num[end];
        else
            return num[start];
    }
};
