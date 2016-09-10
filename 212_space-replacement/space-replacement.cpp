/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 15-11-23 21:14
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        /*
        int i, j;
        for (i=0; i<length; i++) {
            if (string[i]==' ') {
                length += 2;
                for (j=length-1; j>i; j--) {
                    string[j]=string[j-2];
                }
                string[i] = '%';
                string[i+1] = '2';
                string[i+2] = '0';
            }
        }
        return length;
        */
        if(length == 0) return 0;
        int len = length;
        for(int i = 0; i < length; i++){
            if(string[i] == ' ')
                len = len + 2;
        }
        int res = len;
        string[len--] = '\0';
        //--len;
        for(int i = length - 1; i >= 0; i--){
            if(string[i] == ' '){
                string[len--] = '0';
                string[len--] = '2';
                string[len--] = '%';
            }
            else
                string[len--] = string[i];
        }
        return res;
    }
};  
