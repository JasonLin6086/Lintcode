/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 15-09-18 13:03
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        int lengthSource=0, lengthTarget=0;
        int i, j;
        if (source==NULL || target==NULL) {
            return -1;
        }
        for (i=0; source[i]!='\0'; i++) {
            lengthSource++;
        }
        for (i=0; target[i]!='\0'; i++) {
            lengthTarget++;
        }
        if (lengthSource==0 && lengthTarget!=0) {
            return -1;
        }
        
        if (lengthSource!=0 && lengthTarget==0) {
            return 0;
        }
        
        if (lengthSource==0 && lengthTarget==0) {
            return 0;
        }
        for (i=0; i<lengthSource-lengthTarget; i++) {
            for (j=0; j<lengthTarget; j++) {
                if (source[i+j] != target[j]) {
                    break;
                }
                if (j+1 == lengthTarget) {
                    return i;
                }
            }
        }
        return -1;
    }
};

