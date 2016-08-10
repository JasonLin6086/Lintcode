/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/paint-fence
@Language: C++
@Datetime: 16-08-04 02:15
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n == 0) {
          return 0;
        }
        if (n == 1) {
          return k;
        }
        if (n == 2) {
          return k * k;
        }
    
        // fsame(n): the number of combs, whose last digits are the same.
        // fdiff(n): the number of combs, whose last digits are different.
        int fsame = k, fdiff = k * (k - 1);
        for (int p = 3; p <= n; ++p) {
          int fsame1 = fdiff;
          int fdiff1 = (fsame + fdiff) * (k - 1);
          fsame = fsame1;
          fdiff = fdiff1;
        }
    
        return fsame + fdiff;
    }
};