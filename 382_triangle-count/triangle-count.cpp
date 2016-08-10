/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/triangle-count
@Language: C++
@Datetime: 15-09-26 18:08
*/

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int size = S.size();
        if (size <= 2) return 0;
        sort(S.begin(), S.end());
        int res = 0;
        for (int end = size - 1; end > 1; end--) {
            int start = 0, beforeEnd = end - 1;
            while (start < beforeEnd) {
                if (S[start] + S[beforeEnd] <= S[end]) {
                        start++;
                } else {
                    res += beforeEnd - start;//key point
                    beforeEnd--;
                }
            }
        }
        return res;
    }
};
