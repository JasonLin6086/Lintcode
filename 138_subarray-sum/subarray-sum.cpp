/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 15-12-01 16:36
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int sum=0, size = nums.size(), i;
        unordered_map<int, int> hash;
        hash[0] = 0;
        vector<int> result;
        for (i=0; i<size; i++) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                result.push_back(hash[sum]);
                result.push_back(i);
                return result;
            } else {
                hash[sum] = i+1;
            }
        }
        return result;
    }
};
