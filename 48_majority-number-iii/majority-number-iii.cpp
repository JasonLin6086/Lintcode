/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/majority-number-iii
@Language: C++
@Datetime: 15-09-22 16:59
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int len = nums.size();
        if (len < k) {
            return -1;
        }
        unordered_map<int, int> map;
        for (int x : nums) {
            if (map.size() < k && !map[x]) {
                map[x] = 1;
            } else if (map[x]) {
                map[x] = map[x] + 1;
            } else {
                unordered_map<int, int> tmp;
                for (auto key : map) {
                    if (map[key.first] > 1) {
                        tmp[key.first] = map[key.first] - 1;
                    }
                }
                map = tmp;
            }
        }
        int result = 0;
        int count = 0;
        for (auto key : map) {
            if (map[key.first] > count) {
                result = key.first;
                count = map[key.first];
            }
        }
        return result;
    }
};

