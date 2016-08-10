/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/count-of-smaller-number
@Language: C++
@Datetime: 15-12-08 18:07
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> result;
        int size = A.size();
        int qSize = queries.size();
        if (size < 0 || (size == 0 && qSize == 0)) return result;
        if (size ==0 && qSize !=0) return vector<int>(qSize);
        sort(A.begin(), A.end());
        int i;
        for (i=0; i<qSize; i++) {
            int query = queries[i];
            int j = -1, k = size;
            while (j <= k) {
                int mid = j + (k - j) / 2;
                if (A[mid] < query) {
                    j = mid + 1;
                } else {
                    k = mid - 1;
                }
            } 
            //if found, target < A[j]
            int count = j==-1 ? 0 : j;
            result.push_back(count);
        }
        return result;
    }
};