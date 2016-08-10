/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/maximum-subarray-ii
@Language: C++
@Datetime: 15-09-22 20:18
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size==0) return -1;
        vector<int> sumFront(size,0);
        vector<int> sumBackward(size,0);
        getSumFront(sumFront,nums);
        getSumBackward(sumBackward,nums);
        int i, maxTwo=INT_MIN;
        for (i=0; i<size-1; i++) {
            maxTwo = max(maxTwo,sumFront[i]+sumBackward[i+1]);
        }
        return maxTwo;
    }
private:
    void getSumFront(vector<int> &rst, vector<int> &nums) {
        int sum=0, minSum=0, maxSum=INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            minSum = min(minSum, sum);
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            rst[i] = maxSum;
        }
    }
    void getSumBackward(vector<int> &rst, vector<int> &nums) {
        int sum=0, minSum=0, maxSum=INT_MIN;
        for (int i=nums.size()-1; i>=0; i--) {
            minSum = min(minSum, sum);
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            rst[i] = maxSum;
        }
    }
};

