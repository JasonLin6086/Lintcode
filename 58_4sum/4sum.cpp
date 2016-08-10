/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/4sum
@Language: C++
@Datetime: 15-09-25 15:40
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int size = nums.size();
        vector<vector<int>> result;
        if (size<4) {
            return result;
        }
        int i, x;
        sort(nums.begin(), nums.end());
        for (i=0; i<size-3; i++) {
            if (i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int remain = target - nums[i];
            for (x=i+1; x<size-2; x++) {
                int j = x+1;
                int k = size-1;
                int tmpSum;
                while (j < k)
                {
                    tmpSum = nums[x] + nums[j] + nums[k];
    
                    if (tmpSum == remain)
                    {
                        result.push_back({nums[i], nums[x], nums[j], nums[k]});
                        ++j;
                        while (j < nums.size() && nums[j] == nums[j - 1])
                            ++j;
                        --k;
                        while (k >= 0 && nums[k] == nums[k + 1])
                            --k;
                    }
                    else if (tmpSum > remain) 
                        --k;
                    else 
                        ++j;
                }
            }
        }
        sort(result.begin(),result.end());
        auto last = unique(result.begin(), result.end());
        result.erase(last, result.end());
        return result;
    }
};

