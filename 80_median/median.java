/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/median
@Language: Java
@Datetime: 16-03-09 18:18
*/

public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    public int median(int[] nums) {
        // write your code here
        if (nums==null || nums.length==0) return 0;
        int length = nums.length;
        int pos = (length%2==0 ? length/2-1 : length/2);
        int result = helper(nums, 0, length-1, pos);
        return result;
    }
    private int helper(int[] nums, int start, int end, int pos) {
        int pivot = end;
        int l = start, r = end;
        while (l < r) {
            while (l < r && nums[l] < nums[pivot]) {
                l++;
            }
            while (l < r && nums[r] >= nums[pivot]) {
                r--;
            }
            //if (l == r) break;
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
        }
        int tmp = nums[pivot];
        nums[pivot] = nums[r];
        nums[r] = tmp;
        if (l == pos) return nums[pos];
        else if (pos > l) return helper(nums, l+1, end, pos);
        else return helper(nums, start, l-1, pos);
    }
}
