/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/super-ugly-number
@Language: C++
@Datetime: 16-06-30 04:11
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        vector<int> result(n+1, INT_MAX);
        result[0] = 1;
        vector<int> promise(primes.size(), 0);
        for (int i=1; i<=n; i++) {
            for (int j=0; j<primes.size(); j++) {
                result[i] = min(primes[j]*result[promise[j]], result[i]);
            }
            for(int j=0; j<primes.size(); j++){
                if(primes[j]*result[promise[j]]==result[i]){
                    promise[j]++;
                }
            }
        }
        return result[n-1];
    }
};