/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 16-07-13 18:46
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        if( n == 1 ) return true;

        unordered_map< int, bool > m;

        int i, temp;

        while(true) {
            temp = 0;
            while(n > 0) {
                i = n % 10;
                temp += i * i;
                n /= 10;
            }
            if ( temp == 1 ) return true;
            if( m[temp]++ ) return false;
            n = temp;
        }        
    }
};