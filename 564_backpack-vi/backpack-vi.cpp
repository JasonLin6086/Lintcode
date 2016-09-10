/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/backpack-vi
@Language: C++
@Datetime: 16-08-10 06:26
*/

class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        int size = nums.size();
        if (size == 0 || target == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<int> result(target+1);
        result[0] = 1;
        for (int i=0; i<=target; i++) {
            if (result[i] == 0) {
                //cout<<i<<endl;
                continue;
            }
            for (int j = 0; j < size && i + nums[j] <= target; ++j) {
                int t = i + nums[j];
                result[t] += result[i];
            }
            //cout<<"i="<<i<<":"<<result[i]<<endl;
        }
        return result[target];
    }
};