/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 16-04-08 17:00
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int size = nums.size();
        
        if (size<=3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        sort(nums.begin(), nums.end());
        int i, result, temp;
        result = nums[0]+nums[1]+nums[2];
        for (i=0; i<size-2; i++) {
            int j=i+1, k=size-1;
            while(j < k) {
                temp = nums[i]+nums[j]+nums[k];
                if (abs(target-result) > abs(target-temp)) {
                    result = temp;
                    if (result==target) {
                        return result;
                    }
                }
                ( temp > target ) ? k-- : j++;
            }
        }
        return result;
    }
};

