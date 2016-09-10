/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/permutation-sequence
@Language: C++
@Datetime: 16-03-28 15:52
*/

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        string sb = "";
        vector<int> num;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            num.push_back(i);
        }
        for (int i = 0, l = k - 1; i < n; i++) {
            fact /= (n - i);
            int index = (l / fact);
            sb +=to_string(num[index]);
            num.erase(num.begin()+index);
            l -= index * fact;
        }
        return sb;        
    }
};