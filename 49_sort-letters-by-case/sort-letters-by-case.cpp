/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/sort-letters-by-case
@Language: C++
@Datetime: 15-11-04 15:45
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int size = letters.size();
        if (size<=1) return;
        int pl=0, pr=size-1;
        int current=0;
        while (current<=pr) {
            if ('z' - letters[current] <= 26) {
                swap(letters[current],letters[pl]);
                current++;
                pl++;
            } else {
                swap(letters[current],letters[pr]);
                pr--;
            }
        }
    }
};

