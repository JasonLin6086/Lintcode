/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/coins-in-a-line-ii
@Language: C++
@Datetime: 15-11-06 18:52
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int size = values.size();
        if (size<=2) return true;
        vector<int> maxGets(size+2);
        vector<bool> alsoGetNext(size, true);
        //initial
        maxGets[size-1] = values[size-1];
        maxGets[size-2] = values[size-1] + values[size-2];
        int i;
        for(i=size-3; i>=0; i--) {
            int notGetNext;
            if (alsoGetNext[i+1]) {
                notGetNext = values[i] + maxGets[i+3];
            } else {
                notGetNext = values[i] + maxGets[i+2];
            }
            int getNext, tmp = values[i] + values[i+1];
            if (alsoGetNext[i+2]) {
                getNext = tmp + maxGets[i+4];
            } else {
                getNext = tmp + maxGets[i+3];
            }
            maxGets[i] = max(notGetNext, getNext);
            if (notGetNext>getNext) alsoGetNext[i] = false;
        }
        if (alsoGetNext[0]) return maxGets[0] > maxGets[2];
        return maxGets[0] > maxGets[1];
    }
};
