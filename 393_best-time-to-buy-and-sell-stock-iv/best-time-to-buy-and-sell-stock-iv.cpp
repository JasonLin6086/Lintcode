/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iv
@Language: C++
@Datetime: 15-12-07 21:51
*/

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(n<=1 || k<1)
            return 0;

        int temp = 0;
        int count = 0;
        int i;
        for(i=1; i<n; i++)
        {
            if(prices[i] - prices[i-1] > 0)
            {
                temp = temp + prices[i] - prices[i-1];
                count = count + 1;
            }
        }

        if(count < k)
            return temp; // When k is big, dynamic programming might become time consuming

        // Dynamic programming
        vector<int> curProfit(n, 0);
        vector<int> preProfit(n, 0);

        int lowCost;
        int j;
        for(j=0; j<k; j++)
        {
            lowCost = prices[0];
            for(i=1; i<n; i++)
            {
                if(curProfit[i-1] < prices[i] - lowCost)
                    curProfit[i] = prices[i] - lowCost;
                else
                    curProfit[i] = curProfit[i-1];

                if(prices[i]-preProfit[i-1] < lowCost)
                    lowCost = prices[i]-preProfit[i-1];
            }
            preProfit = curProfit;
        }
        return curProfit[n-1];
    }
};
