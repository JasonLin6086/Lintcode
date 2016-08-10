/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/candy
@Language: C++
@Datetime: 16-05-16 15:38
*/

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        int res = 0;
        vector<int> num(ratings.size(), 1);
        for (int i = 0; i < (int)ratings.size() - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) num[i + 1] = num[i] + 1;
        }
        for (int i = (int)ratings.size() - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) num[i - 1] = max(num[i] + 1, num[i - 1]);
        }
        for (int i = 0; i < num.size(); ++i) {
            res += num[i];
        }
        return res;
    }
};