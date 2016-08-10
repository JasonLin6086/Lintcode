/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/maximum-subarray-difference
@Language: C++
@Datetime: 15-09-14 16:33
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
        int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int size = nums.size();
        
//以数组中数的个数为维度，定义四个辅助数组
        int *maxArray = new int[size];           
        int *preMinArray = new int[size];
        int *minArray = new int[size];
        int *postMaxArray = new int[size];

//填充辅助数组的值
        maxArray[0] = nums[0];
        preMinArray[0] = nums[0];
        for(int i = 1; i < size; i++){
            maxArray[i] = max(nums[i], nums[i] + maxArray[i - 1]); 
            preMinArray[i] = min(nums[i], nums[i] + preMinArray[i - 1]);
        }
        
        minArray[size - 1] = nums[size - 1];
        minArray[size - 2] = nums[size - 1];
        postMaxArray[size - 1] = nums[size - 1];
        postMaxArray[size - 2] = nums[size - 1];
        
        for(int i = size - 3; i >= 0; i--){
            minArray[i] = min(nums[i + 1], nums[i + 1] + minArray[i + 1]);
            postMaxArray[i] = max(nums[i + 1], nums[i + 1] + postMaxArray[i + 1]);
        }
        
//利用四个辅助数组中的值计算最终的结果
        int result = abs(maxArray[0] - minArray[0]);
        for(int i = 1; i < size - 1; i++){
            if(abs(maxArray[i] - minArray[i]) > result)
                result = abs(maxArray[i] - minArray[i]);
            if(abs(preMinArray[i] - postMaxArray[i]) > result)
                result = abs(preMinArray[i] - postMaxArray[i]);
        }
        
//删除辅助数组
        delete []maxArray;
        delete []minArray;
        delete []preMinArray;
        delete []postMaxArray;
        
        return result;
    }
};

