/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 15-09-12 15:55
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        /*int size = nums.size();
        if (k==0||size==0) return -1;
        for (int i=0; i<k; i++) {
            for (int j=1; j<size; j++) {
                if (nums[j]<nums[j-1]) {
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        return nums[size-k];*/
        return helper(nums, k, 0, nums.size()-1);
    }
private:
   int helper(vector<int> A, int k, int start, int end) 
   {
       int left = start+1, right = end;
       while(left <= right) {
           while(left <= right && A[left] >= A[start]) left++;
           while(left <= right && A[right] <= A[start]) right--;
           
           if (left < right) swap(A[left], A[right]);
       }
       
       swap(A[start], A[right]);
       
       if (right+1 == k) return A[right];
       else if (right+1 > k) return helper(A, k, start, right-1);
       else return helper(A, k, right+1, end);
   }
};
