/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 15-09-04 15:14
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        vector<vector<int>> result;
        if (size<3) {
            return result;
        }
        int i;
        sort(nums.begin(), nums.end());
        for (i=0; i<size-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1;
            int k = size-1;
            int ans;
            while (j < k)
            {
                ans = nums[i] + nums[j] + nums[k];

                if (ans == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (j < nums.size() && nums[j] == nums[j - 1])
                        ++j;
                    --k;
                    while (k >= 0 && nums[k] == nums[k + 1])
                        --k;
                }
                else if (ans > 0) 
                    --k;
                else 
                    ++j;
            }
        }
        return result;
    }
};

