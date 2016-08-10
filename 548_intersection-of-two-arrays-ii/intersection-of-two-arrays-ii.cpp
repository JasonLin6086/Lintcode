/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays-ii
@Language: C++
@Datetime: 16-06-02 16:23
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
        unordered_map<int, int> ump;
        for (int i=0; i<size; i++) {
            ump[nums1[i]] ++;
        }
        vector<int> result;
        for (int i=0; i<nums2.size(); i++) {
            if (ump[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                ump[nums2[i]] --;
            }
        }
        return result;
    }
};