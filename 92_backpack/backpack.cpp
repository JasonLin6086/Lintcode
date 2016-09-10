/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 16-08-10 21:54
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty() || m < 1) {
            return 0;
        }

        const int N = A.size();
        vector<bool> result(m+1);

        result[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = m; j >= 0; j--) {
                if (j >= A[i] && result[j - A[i]]) {
                    result[j] = true;
                }
            }
        }

        // return the largest i if true
        for (int i = m; i > 0; i--) {
            if (result[i]) {
                return i;
            }
        }
        return 0;
    }
};
