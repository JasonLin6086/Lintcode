/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: C++
@Datetime: 16-06-02 16:20
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        int size = nums1.size();
        unordered_set<int> us;
        for (int i=0; i<size; i++) {
            us.insert(nums1[i]);
        }
        vector<int> result;
        for (int i=0; i<nums2.size(); i++) {
            if (us.find(nums2[i]) != us.end()) {
                result.push_back(nums2[i]);
                us.erase(nums2[i]);
            }
        }
        return result;
    }
};