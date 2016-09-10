/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/subarray-sum-closest
@Language: C++
@Datetime: 15-07-20 22:36
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int size = nums.size();
        vector<int> result;
        if (nums.empty()) {
            return result;
        }
        vector<pair<int, int>> sums(size+1);
        int i;
        for (i=0; i<size; i++) {
            sums[i+1].first = sums[i].first + nums[i];
            sums[i+1].second = i+1;
        }
        sort(sums.begin(), sums.end());
        int min_diff = INT_MAX;
        int sum_diff;
        int index=1;
        for (i=1; i<size+1; i++) {
            sum_diff = abs(sums[i].first - sums[i-1].first);
            if (sum_diff < min_diff) {
                min_diff = sum_diff;
                index = i;
            }
        }
        int left_idx = min(sums[index].second, sums[index-1].second);
        int right_idx = max(sums[index].second, sums[index-1].second)-1;
        result.push_back(left_idx);
        result.push_back(right_idx);
        return result;
    }
};

