/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 15-11-21 21:35
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int i;
        /*
        vector <int> result(n+1, 1);
        
        for (i=2; i<n+1; i++) {
            result[i] = result[i-1] + result[i-2];
        }
        
        return result[n];
        */
        vector<int> result(n+1);
        result[0] = 1;
        result[1] = 1;
        for (i=2; i<=n; i++) {
            result[i] = result[i-2] + result[i-1];
        }
        return result[n];
    }
};

