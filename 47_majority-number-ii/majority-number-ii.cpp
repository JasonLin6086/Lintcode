/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 15-09-07 20:48
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code hereint
        int size = nums.size();
        int a=0, b=0, countA=0, countB=0;
        bool isA=false, isB=false;
        int i;
        for (auto tmp : nums) {
            if (!isA || a==tmp) {
                countA++; a=tmp; isA=true;
            } else if (!isB || b==tmp) {
                countB++; b=tmp; isB=true;
            } else {
                countA--;
                countB--;
                if (countA==0) {
                    isA=false;
                }
                if (countB==0) {
                    isB=false;
                }
            }
        }
        if (!isA) return b;
        if (!isB) return a;
        int c=0;
        for (auto x : nums) {
            if (a==x) c++;
        }
        return (c>size/3 ? a : b);
    }
};

