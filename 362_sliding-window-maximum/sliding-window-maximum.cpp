/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/sliding-window-maximum
@Language: C++
@Datetime: 15-09-23 20:00
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        if(nums.size() == 0 || k == 0)  
            return res;  
        deque<int> Q;  
        for(int i=0;i<k;i++)  
        {  
            while(!Q.empty()&&nums[i]>=nums[Q.back()])  
                Q.pop_back();  
            Q.push_back(i);  
        }  
        res.push_back(nums[Q.front()]);  
          
        for(int i=k;i<nums.size();i++)  
        {  
            while(!Q.empty()&&nums[i]>=nums[Q.back()])  
                Q.pop_back();  
            while(!Q.empty()&& i-Q.front()>=k)  
                Q.pop_front();  
            Q.push_back(i);  
            res.push_back(nums[Q.front()]);  
        }  
        return res;  
    }
};

