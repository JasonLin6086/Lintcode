/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: C++
@Datetime: 16-07-13 19:19
*/

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        int oriSize = originalStr.size();
        if (size > oriSize) {
            originalStr.resize(size);
            for (int i=size-1; i>=size-oriSize; i--) {
                originalStr[i] = originalStr[oriSize-size+i];
            }
            for (int i=0; i<size-oriSize; i++) {
                originalStr[i] = padChar;
            } 
        }
        return originalStr;
    }
};
