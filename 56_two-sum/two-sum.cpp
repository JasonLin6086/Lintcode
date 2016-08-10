/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 15-09-23 05:22
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        int size = nums.size();
        unordered_map<int, int> hash;
        int i;
        vector<int> result;
        for (i=0; i<size; i++) {
            int remain = target - nums[i];
            //unordered_map<int,int>::const_iterator got = hash.find(remain);
            //if (got != hash.end()) {
            if (hash[remain]) {
                result.push_back(hash[remain]);
                result.push_back(i+1);
                return result;
            } else {
                hash[nums[i]] = i + 1;
            }
        }
    }
};

