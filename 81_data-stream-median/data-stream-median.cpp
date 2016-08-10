/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/data-stream-median
@Language: C++
@Datetime: 16-06-30 15:35
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        // min_bst stores the larger half seen so far.
        multiset<int> min_bst;
        // max_bst stores the smaller half seen so far.
        multiset<int, greater<int>> max_bst;

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {

            // Balance smaller half and larger half.
            if (max_bst.empty() || nums[i] > *max_bst.begin()) {
                min_bst.insert(nums[i]);
                if (min_bst.size() > max_bst.size() + 1) {
                    max_bst.insert(*min_bst.begin());
                    min_bst.erase(min_bst.begin());
                }
            } else {
                max_bst.insert(nums[i]);
                if (max_bst.size() > min_bst.size()) {
                    min_bst.insert(*max_bst.begin());
                    max_bst.erase(max_bst.begin());
                }
            }

            ans.push_back(min_bst.size() == max_bst.size() ?
                             *max_bst.begin() : *min_bst.begin());
        }

        return ans;
    }
};

