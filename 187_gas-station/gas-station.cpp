/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/gas-station
@Language: C++
@Datetime: 15-08-17 06:35
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        if (gas.size() != cost.size()) {
            return -1;
        }
        int size=gas.size(), i, start = 0, total = 0;
        int gasTank=0;
        for (i=0; i<size; i++) {
            int remaining = gas[i] - cost[i];
            if (gasTank >= 0) 
                gasTank = gasTank + remaining;
            else {
                start = i;
                gasTank = remaining;
            }
            total = total + remaining;
        }
        if (total >= 0) 
            return start;
        else {
            return -1;
        }
    }
};
