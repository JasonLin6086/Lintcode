/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 15-11-06 21:00
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        int i;
        int hashMap[26] = {0};
        for (i=0; i<sizeA; i++) {
            hashMap[A[i]-'A'] ++;
        }
        for (i=0; i<sizeB; i++) {
            hashMap[B[i]-'A'] --;
            if (hashMap[B[i]-'A'] < 0) {
                return false;
            }
        }
        return true;
    }
};

