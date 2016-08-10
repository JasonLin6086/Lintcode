/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/largest-rectangle-in-histogram
@Language: C++
@Datetime: 15-09-18 04:48
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
     stack<int> S;  
       height.push_back(0);  
       int sum = 0;  
       for (int i = 0; i < height.size(); i++) {  
            if (S.empty() || height[i] > height[S.top()]) S.push(i);  
         else {  
                 int tmp = S.top();  
                 S.pop();  
                 sum = max(sum, height[tmp]*(S.empty()? i : i-S.top()-1));  
                 i--;  
            }  
       }  
       return sum;  
    }
};

