/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 15-07-19 06:50
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        int length=0, tmpLength=0;
        int i,j;
        if (sizeA==0 && sizeB==0) {
            return 0;
        }
        for (i=0; i<sizeA; i++) {
            for (j=0; j<sizeB; j++) {
                tmpLength = 0;
                while (i+tmpLength < sizeA &&
                       j+tmpLength < sizeB &&
                       A[i+tmpLength] == B[j+tmpLength]) {
                           tmpLength ++;
                       }
                if (tmpLength > length) {
                    length = tmpLength;
                }
            }
        }
        return length;
    }
};

