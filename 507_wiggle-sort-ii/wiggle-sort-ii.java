/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/wiggle-sort-ii
@Language: Java
@Datetime: 16-03-09 18:41
*/

public class Solution {
    /**
     * @param nums a list of integer
     * @return void
     */
    public void wiggleSort(int[] nums) {
        // Write your code here
        int n = nums.length;
        int mid = n / 2 - (n % 2 == 0 ? 1 : 0);
        int[] sorted = Arrays.copyOf(nums, n);
        Arrays.sort(sorted);
    
        for (int i = 0, copyOffset = 0; copyOffset <= mid; copyOffset++, i += 2) {
            nums[i] = sorted[mid - copyOffset];
            if (i + 1 < n)
                nums[i + 1] = sorted[n - copyOffset - 1];
        }
        /*for (int i : nums) {
            System.out.print(i+" ");
        }
        System.out.println();*/
    }
}
