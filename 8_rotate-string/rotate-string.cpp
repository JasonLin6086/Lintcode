/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: C++
@Datetime: 15-12-01 17:42
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        
        int size = str.size();
        if (size<=1) return;
        offset = offset % size;
        
        swapString(str, 0, size - offset - 1);
        swapString(str, size - offset, size - 1);
        swapString(str, 0, size - 1);
        
        //rotate(str.begin(), str.end()-offset, str.end());
    }
private:
    void swapString(string &str, int start, int end) {
        /*
        while (start < end) {
            swap(str[start++], str[end--]);
        }
        */
        reverse(str.begin()+start, str.begin()+end+1);
    }
};

