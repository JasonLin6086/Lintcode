/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii
@Language: C++
@Datetime: 15-11-06 17:45
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
        if (size<=1) return 0;
        int i;
        vector<int> leftToRight(size,0);
        vector<int> rightToLeft(size,0);
        int globalMin=prices[0], globalMax=prices[size-1];
        
        for (i=1; i<size; i++) {
            globalMin = min(globalMin, prices[i]);
            leftToRight[i] = max(leftToRight[i-1], prices[i]-globalMin);;
        }
        
        for (i=size-2; i>=0; i--) {
            globalMax = max(globalMax, prices[i]);
            rightToLeft[i] = max(rightToLeft[i+1], globalMax - prices[i]);
        }
        
        int rst = 0;
        for (i=0; i<size; i++) {
            int tmpRst = leftToRight[i] + rightToLeft[i];
            rst = max(rst, tmpRst);
        }
        
        return rst;
    }
};
