/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 15-09-25 16:12
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int size = L.size();
        if (size==0) return 0;
        if (size==1) return (int)L[0]/k;
        int maxLen = 0;
        int i;
        for (i=0; i<size; i++) {
            maxLen = max(maxLen, L[i]);
        }
        int start=0, end=maxLen, mid;
        while (start+1 < end) {
            int count=0;
            mid = start + (end - start)/2;
            if (mid==0) {
                count = INT_MAX;
            } else {
                for (int a=0; a<size; a++) {
                    count += L[a]/mid;
                }
                if (count>=k) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }
        return start;
    }
};
