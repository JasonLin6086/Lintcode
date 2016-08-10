/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock
@Language: C++
@Datetime: 16-04-08 17:05
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int size = prices.size();
        if (size<2) return 0;
        int i, currMin=prices[0];
        int maxProfit = 0;
        
        for (i=1; i<size; i++) {
            currMin = min(currMin, prices[i]);
            maxProfit = max(maxProfit, prices[i]-currMin);
        }
        return maxProfit;
    }
};

