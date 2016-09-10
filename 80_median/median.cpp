/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 16-03-09 18:07
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int size = nums.size();

        int k = (size%2 == 0) ? size/2-1 : size/2;
        int result = medianHelper(nums, 0, size-1, k);
        return result;
    }
private:
    int medianHelper(vector<int> &nums, int start, int end, int pos) {
        int pivot = end;
        int l = start, r = end;
        while (l<r) {
            while (l < r && nums[l] < nums[pivot]) {
                l++;
            }
            while (l < r && nums[r] >= nums[pivot]) {
                r--;
            }
            if (l==r) break;
            swap(nums[l],nums[r]);
        }
        swap(nums[r],nums[pivot]);
        if (l==pos) return nums[l];
        if (l<pos) return medianHelper(nums,l+1,end, pos);
        else return medianHelper(nums,start,l-1,pos);
    }
};

